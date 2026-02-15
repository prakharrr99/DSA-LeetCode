class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1; int j=b.size()-1; int c=0;
        string s;
        while(i>=0 && j>=0){
            if(c==0){
                if(a[i]=='1' && b[j]=='1'){
                    c=1;
                    s.push_back('0');
                }
                else if(a[i]=='1' || b[j]=='1'){
                    c=0;
                    s.push_back('1');
                }
                else{
                    c=0;
                    s.push_back('0');
                }
            }
            else{
                if(a[i]=='1' && b[j]=='1'){
                    c=1;
                    s.push_back('1');
                }
                else if(a[i]=='1' || b[j]=='1'){
                    c=1;
                    s.push_back('0');
                }
                else{
                    c=0;
                    s.push_back('1');
                }
            }
            i--; j--;
        }
        while(i>=0){
            if(c==1){
                if(a[i]=='1'){
                    s.push_back('0');
                    c=1;
                }
                else{
                    s.push_back('1');
                    c=0;
                }
            }
            else s.push_back(a[i]);
            i--;
        }
        while(j>=0){
            if(c==1){
                if(b[j]=='1'){
                    s.push_back('0');
                    c=1;
                }
                else{
                    s.push_back('1');
                    c=0;
                }
            }
            else s.push_back(b[j]);
            j--;
        }
        if(c!=0) s.push_back('1');
        reverse(s.begin(),s.end());
        return s;
    }
};