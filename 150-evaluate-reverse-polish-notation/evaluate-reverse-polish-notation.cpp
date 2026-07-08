class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto it:tokens){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int first=stoi(st.top());
                st.pop();
                int second=stoi(st.top());
                st.pop();
                int val=-1;
                if(it=="+") val=(second+first);
                else if(it=="-") val=(second-first);
                else if(it=="/") val=(second/first);
                else val=(second*first);

                st.push(to_string(val));
            }
            else st.push(it);
        }
        string p=st.top();
        int balue=stoi(p);
        return balue;
    }
};