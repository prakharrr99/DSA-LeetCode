class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int m=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            m=min(m,landStartTime[i]+landDuration[i]);
        }
        int mi=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            mi=min(mi,waterStartTime[i]+waterDuration[i]);
        }

        int a=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            if(waterStartTime[i]<=m){
                a=min(a,waterDuration[i]);
            }
            else{
                a=min(a,waterStartTime[i]-m+waterDuration[i]);
            }
        }
        
        m=m+a;
        // cout<<m<<endl;

        int b=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            if(landStartTime[i]<=mi){
                b=min(b,landDuration[i]);
            }
            else{
                b=min(b,landStartTime[i]-mi+landDuration[i]);
            }
        }
        mi=mi+b;
        // cout<<mi;

        return min(m,mi);
        
    }
};