class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        stack<string> op;
        
        for(int i=tokens.size()-1;i>=0;i--){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") op.push(tokens[i]);
        }
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                string str=op.top(); op.pop();
                int a=stoi(s.top()); s.pop();
                int b=stoi(s.top()); s.pop();
                if(str=="+"){
                    string c=to_string(a+b);
                    s.push(c);
                }
                else if(str=="-"){
                    string c=to_string(b-a);
                    s.push(c);
                }
                else if(str=="*"){
                    string c=to_string(a*b);
                    s.push(c);
                }
                else{
                    string c=to_string(b/a);
                    s.push(c);
                }
            }
            else s.push(tokens[i]);
        }
        return stoi(s.top());
    }
};