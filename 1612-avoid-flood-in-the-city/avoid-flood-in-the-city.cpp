class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int,int> fullday;
        vector<int> ans(rains.size(),0);

        for(int i=0;i<rains.size();i++){
            if(rains[i]==0) continue;
            if(fullday[rains[i]]!=0){  
                int j=fullday[rains[i]];
                while(j<i){
                    if(rains[j]==0){
                        fullday[rains[i]]=i+1;
                        rains[j]=-1;
                        ans[j]=rains[i];
                        ans[i]=-1;
                        break;
                    }
                    j++;
                }
                if(j>=i) return vector<int>();
            }
            else{
                fullday[rains[i]]=i+1;
                ans[i]=-1;
            } 
        }
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0) ans[i]=1;
        }
        return ans;
    }
};