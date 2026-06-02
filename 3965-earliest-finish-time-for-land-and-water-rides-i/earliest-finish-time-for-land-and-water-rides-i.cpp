class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<int>> land;
        vector<vector<int>> water;

        for(int i=0;i<landStartTime.size();i++){
            land.push_back({landStartTime[i],landDuration[i]});
        }

        for(int i=0;i<waterStartTime.size();i++){
            water.push_back({waterStartTime[i],waterDuration[i]});
        }


        int ans=INT_MAX;
        for(int i=0;i<land.size();i++){
            int t=land[i][0]+land[i][1];
            for(int j=0;j<water.size();j++){
                if(water[j][0]>=t){
                    ans=min(ans,t+water[j][0]-t+water[j][1]);
                }
                else{
                    ans=min(ans,t+water[j][1]);
                }
            }
        }
        for(int i=0;i<water.size();i++){
            int t=water[i][0]+water[i][1];
            for(int j=0;j<land.size();j++){
                if(land[j][0]>=t){
                    ans=min(ans,t+land[j][0]-t+land[j][1]);
                }
                else{
                    ans=min(ans,t+land[j][1]);
                }
            }
        }
        return ans;
    }
};