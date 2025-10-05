class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                ss.push(s[i]);
            }
            else if(ss.empty()){
                return false;
            }
            else{
                int a=0;
                if((ss.top()=='[' && s[i]==']') || (ss.top()=='{' && s[i]=='}') || (ss.top()=='(' && s[i]==')')){
                    ss.pop();
                    a=1;
                }
                if(a==0) return false;
            }
        }
        if(ss.empty()) return true;
        return false;
    }
};