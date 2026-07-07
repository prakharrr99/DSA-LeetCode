class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
    
        vector<int> v(intervals.size(),0);
        int ans=0;
        for(int i=0;i<intervals.size();i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            if(v[i]==1) continue;

            for(int j=0;j<intervals.size();j++){
                if(v[j]==1 || i==j) continue;
                int c=intervals[j][0];
                int d=intervals[j][1];
                if(c>b) break;
                if(c>=a && b>=d){
                    v[j]=1;
                }
            }
        }
        for(auto it:v){
            if(it==0) ans++;
        }
        return ans;
    }
};