class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0; int prevmin=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[prevmin]){
                
                time+=min(neededTime[i],neededTime[prevmin]);
                
                if(neededTime[i]>neededTime[prevmin]) prevmin=i;
            }
            else prevmin=i;
        }
        return time;
    }
};