class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> m;
        int j=0; int i=0;
        int a=INT_MIN;
        while(j<s.size()){
            m[s[j]]++;
            while(m[s[j]]>1){
                m[s[i]]--;
                i++;
            }
            a=max(a,j-i+1);
            j++;
        }
        if(a==INT_MIN) return 0;
        return a;
    }
};