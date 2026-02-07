class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1;string s2;
        for(auto it:s){
            if(it=='#' && s1.size()!=0) s1.pop_back();
            else if(it!='#') s1.push_back(it);
        }
         for(auto it:t){
            if(it=='#' && s2.size()!=0) s2.pop_back();
            else if(it!='#') s2.push_back(it);
        }
        return s1==s2;
    }
};