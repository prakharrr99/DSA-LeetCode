class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int i=0; int j=0;
        int length=1;
        unordered_map<int,int> m;
        while(j<s.size()){
            while(m[s[j]]!=0){
                m[s[i]]=0;
                i++;
            } 
            if(m[s[j]]==0){
                m[s[j]]++;
                length=max(length,j-i+1);
                j++;
            }
        }
        return length;
    }
};