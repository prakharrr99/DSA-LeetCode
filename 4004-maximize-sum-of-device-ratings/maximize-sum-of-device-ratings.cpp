class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
       
        for(int i=0;i<units.size();i++){
            sort(units[i].begin(),units[i].end());
        }

        int mini=INT_MAX;
        for(int i=0;i<units.size();i++){
            if(units[i].size()>1){
                mini=min(mini,units[i][0]);
                units[i][0]=units[i][1];
            }
        }
        int m=1e6;
        int id=0;
        for(int i=0;i<units.size();i++){
            if(m>units[i][0]){
                m=units[i][0];
                id=i;
            }
        }

        long long ans=min(mini,units[id][0]);
        
        for(int i=0;i<units.size();i++){
            if(i!=id) ans+=units[i][0];
        }

        return ans;
    }
};