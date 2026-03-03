class Solution {
public:
    string invertrev(string a){
        string s=a;
        for(int i=0,j=s.size()-1;j>i;i++,j--){
            swap(s[i],s[j]);
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        string s2="011";
        for(int i=2;i<n;i++){
            string ss=invertrev(s2);
            s2=s2+"1"+ss;
        }
        char c;
        for(int i=0;i<s2.size() && i<k;i++){
            c=s2[i];
        }
        return c;
    }
};