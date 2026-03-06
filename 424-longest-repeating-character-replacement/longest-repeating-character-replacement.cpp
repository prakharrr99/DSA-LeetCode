class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0; int j=0;
        vector<int> a(26,0);
        int ans=0;
        while(j<s.size()){
            a[s[j]-'A']++;
            int m=INT_MIN;
            for(int p=0;p<26;p++){
                m=max(m,a[p]);
            }
            while(j-i+1-m>k){
                a[s[i]-'A']--;
                i++;
                m=INT_MIN;
                for(int p=0;p<26;p++) m=max(m,a[p]);
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};