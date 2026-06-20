class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> v(n,0);
        for(int i=0;i<lights.size();i++){
            if(lights[i]!=0){
                int s=max(0, i - lights[i]);
                int e=min(n - 1, i + lights[i]);
                v[s]+=1;
                if(e<n-1) v[e+1]+=-1;
            }
        }
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }
        int bulb=0;
        
        int i=0;
        while(i<v.size()){
            if(v[i]==0){
                if(i<n-1 && v[i+1]==0){
                    bulb++;
                    i+=2;
                }
                else bulb++;
            }
            i++;
        }
        return bulb;
    }
};