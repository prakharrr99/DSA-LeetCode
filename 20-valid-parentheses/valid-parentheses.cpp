class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(int i=0;i<str.size();i++){
            if(str[i]=='{' || str[i]=='[' || str[i]=='(') s.push(str[i]);
            else{
                if(s.size()==0) return false;
                if((str[i]=='}' && s.top()=='{') || (str[i]==']' && s.top()=='[') || (str[i]==')' && s.top()=='(')) 
                    s.pop();
                else return false;
            }
        }
        if(s.size()==0) return true;
        return false;
    }
};