class Solution {
public:
    bool valid(int mid,vector<int>& bloomDay, int m, int k){
        int count=0;
        int b=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) count++;
            if(count==k){
                b++;
                count=0;
            }
            if(count!=0 && bloomDay[i]>mid){
                count=0;
            }
        }
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<1LL*m*k) return -1;

        int low=1;
        int high=INT_MIN;
        for(int i=0;i<bloomDay.size();i++) high=max(high,bloomDay[i]);
        int ans=-1;

        while(high>=low){
            int mid=low+(high-low)/2;
            if(valid(mid,bloomDay,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};