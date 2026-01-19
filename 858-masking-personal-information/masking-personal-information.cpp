class Solution {
private:
    void lower(string& s){
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=tolower(s[i]);
            }
        }
    }
public:
    string maskPII(string s) {
        string ans;
        int xx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='@'){
                xx=1; break;
            }
        }
        if(xx==1){
            lower(s);
            int c=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='@') break;
                c++;
            }
            ans.push_back(s[0]);
            for(int i=1;i<=5;i++){
                ans.push_back('*');
            }
            for(int i=c-1;i<s.size();i++){
                ans.push_back(s[i]);
            }
        }
        else{
            string sos;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='+' ||s[i]=='-' || s[i]=='(' || s[i]==')' || s[i]==' ') continue;
                else{
                    sos.push_back(s[i]);
                }
                if(sos.size()==4) break;
            }
            ans="***-***-";
            for(int i=sos.size()-1;i>=0;i--){
                ans.push_back(sos[i]);
            }
            int c=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='+' ||s[i]=='-' || s[i]=='(' || s[i]==')' || s[i]==' ') continue;
                else c++;
            }
            if(c==10){
                return ans;
            }
            else if(c==11){
                string pop="+*-";
                pop=pop+ans;
                return pop;
            }
            else if(c==12){
                string pop="+**-";
                pop=pop+ans;
                return pop;
            }
            else{
                string pop="+***-";
                pop=pop+ans;
                return pop;
            }
        }
        return ans;
    }
};