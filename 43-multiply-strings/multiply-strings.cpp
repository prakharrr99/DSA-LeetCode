class Solution {
public:
    string add(string a,string b){
        if(b.size()==0) return a;
        if(a.size()==0) return b;
        int i=a.size()-1; int j=b.size()-1;
        string aa; int c=0;
        while(i>=0 && j>=0){
            int d=(a[i]-'0'+b[j]-'0'+c)%10;
            c=(a[i]-'0'+b[j]-'0'+c)/10;
            char g=d+'0';
            aa.push_back(g);
            i--; j--;
        }
        while(i>=0){
            int d=(a[i]-'0'+c)%10;
            c=(a[i]-'0'+c)/10;
            char g=d+'0';
            aa.push_back(g);
            i--;
        }
        while(j>=0){
            int d=(b[j]-'0'+c)%10;
            c=(b[j]-'0'+c)/10;
            char g=d+'0';
            aa.push_back(g);
            j--;
        }
        if(c!=0){
            char g=c+'0';
            aa.push_back(g);
        }
        reverse(aa.begin(),aa.end());
        return aa;
    }
    string multiply(string num1, string num2) {
        string yo; int p=0;
        if(num1[0]=='0'|| num2[0]=='0') return "0";
        if(num1.size()>num2.size()) return multiply(num2,num1);
        for(int i=num1.size()-1;i>=0;i--){
            int c=0; string ans;
            for(int j=num2.size()-1;j>=0;j--){
                int a=num1[i]-'0';
                int b=num2[j]-'0';
                int d=(a*b+c)%10;
                c=(a*b+c)/10;
                char v=d+'0';
                ans.push_back(v);
            }
            if(c!=0){
                char v=c+'0';
                ans.push_back(v);
                c=0;
            }
            reverse(ans.begin(),ans.end());
            for(int k=1;k<=p;k++){
                ans.push_back('0');
            }
            yo=add(yo,ans); 
            p++;
        }
        return yo;
    }
};