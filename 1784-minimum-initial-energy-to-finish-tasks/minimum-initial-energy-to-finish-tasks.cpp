class Solution {
public:
    bool valid(vector<vector<int>>& tasks,int v){
        for(int i=0;i<tasks.size();i++){
            if(v>=tasks[i][1]){
                v-=tasks[i][0];
            }
            else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int low=1;
        int high=0;
        for(int i=0;i<tasks.size();i++) high+=tasks[i][1];

        int ans=0;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(valid(tasks,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};