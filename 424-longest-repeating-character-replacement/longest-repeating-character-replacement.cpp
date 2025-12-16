class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0) return 0;
        int i=0; int j=0;
        vector<int> freq(26,0); int maxcount=0; int ans=1;
        while(j<s.size()){
            freq[s[j]-'A']++;
            maxcount=max(maxcount,freq[s[j]-'A']);
            if(j-i+1-maxcount<=k){
                j++;
            }
            else{
                freq[s[i]-'A']--;
                i++;
                ans=max(ans,j-i+1);
                j++;
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};