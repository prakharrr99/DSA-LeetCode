class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> a(s.size(),0);
        if(s[s.size()-1]=='a') a[s.size()-1]=1;
        else a[s.size()-1]=0;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]=='a') a[i]=a[i+1]+1;
            else a[i]=a[i+1];
        }
        int b=0;
        int m=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') m=min(a[i]-1+b,m);
            else m=min(a[i]+b,m);
            if(s[i]=='b') b++;
            
        }
        return m;
    }
};