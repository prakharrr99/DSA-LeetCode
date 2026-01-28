class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        vector<int> freq(256,0);
        if(s.size()!=t.size()) return false;
        int i=0; 
        while(i<s.size()){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]]!=t[i]) return false;
            }
            else{
                if(freq[t[i]]!=0) return false;
                m[s[i]]=t[i];
                freq[t[i]]=1;
            }
            i++;
        }
        return true;
    }
};