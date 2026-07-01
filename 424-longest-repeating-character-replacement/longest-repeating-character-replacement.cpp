class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        vector<int> f(26,0);
        int ans=0;
        while(j<s.size()){
            f[s[j]-'A']++;
            int m=0;
            for(auto it:f) m=max(m,it);
            while(j-i+1-m>k){
                f[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};