class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size()!=goal.size()) return false;
        if(s==goal) return true;

        s=s+s;
        for(int i=0;i<goal.size();i++){
            string str;
            for(int j=i; str.size()!=goal.size() && j<2*goal.size();j++){
                str.push_back(s[j]);
            }
            if(str==goal) return true;
        }
        return false;
    }
};