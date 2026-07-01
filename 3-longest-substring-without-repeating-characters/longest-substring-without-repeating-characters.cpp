class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int i=0,j=0;
        int ans=0;
        while(j<s.size()){
            while(m[s[j]]!=0){
                m[s[i]]--;
                i++;
            }
            m[s[j]]++;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};