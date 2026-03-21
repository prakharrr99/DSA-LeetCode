class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> f(256,0);
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        int a=0;
        int o=0;
        for(int i=0;i<256;i++){
            if(f[i]%2==0) a+=f[i];
            else{
                a+=(f[i]-1);
                o=1;
            }
        }
        return a+o;
    }
};