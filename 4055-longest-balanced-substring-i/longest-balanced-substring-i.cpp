class Solution {
public:
    int longestBalanced(string s) {
        int ans=INT_MIN;
        for(int i=0;i<s.size();i++){
            vector<int> f(26,0);
            for(int j=i;j<s.size();j++){
                f[s[j]-'a']++;
                int p=0;
                int y=0;
                // for(int k=0;k<26;k++){
                //     if(f[k]!=0){
                //         p=f[k];
                //         break;
                //     }
                // }
                // for(int k=0;k<26;k++){
                //     if(f[k]!=0 && p!=f[k]){
                //         y=1; break;
                //     }
                // }
                for(int k=0;k<26;k++){
                    if(p==0 && f[k]!=0) p=f[k];
                    if(p!=0 && f[k]!=0 && f[k]!=p){
                        y=1; break;
                    }
                }
                if(y==0) ans=max(ans,j+1-i);
            }
        }
        if(ans==INT_MIN) return -1;
        return ans;
    }
};