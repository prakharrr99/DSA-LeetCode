class Solution {
public:
    int countHomogenous(string s) {
        int j=0;
        vector<int> v(26,0);
        long long ans=0;
        int M=1e9+7;
        while(j<s.size()){
            if(v[s[j]-'a']==0){
                for(int i=0;i<26;i++){
                    if(v[i]!=0) ans+=((1LL*v[i]*(v[i]+1))/2)%M;
                    v[i]=0;
                }
            }
            v[s[j]-'a']++;
            j++;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0) ans+=((1LL*v[i]*(v[i]+1))/2)%M;
            v[i]=0;
        }
        int t=ans%M;
        return t;
    }
};