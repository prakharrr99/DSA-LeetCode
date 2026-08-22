class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<int> f(26,0);
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']++;
        }

        long long ans=LLONG_MAX;
        for(int i=0;i<26;i++){
            if(f[i]!=0){
                char c=i+'a';
                long long op=0;
                for(int j=0;j<cost.size();j++){
                    if(s[j]!=c) op+=cost[j];
                }
                ans=min(ans,op);
            }
        }
        return ans;
    }
};