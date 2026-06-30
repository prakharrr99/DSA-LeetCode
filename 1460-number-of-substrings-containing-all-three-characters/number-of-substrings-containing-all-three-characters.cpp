class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> f(26,0);
        int i=0;
        int j=0;
        int a=0,b=0,c=0;
        int ans=0;
        while(j<s.size()){
            while(!(a && b && c) && j<s.size()){
                if(s[j]=='a') a++;
                else if(s[j]=='b') b++;
                else c++;
                j++;
            }
            if(a && b && c){
                ans+=(s.size()-j+1);
            }
            if(s[i]=='a') a--;
            else if(s[i]=='b') b--;
            else c--;
            i++;
        }
        while(a && b && c && i<s.size()){
            ans++;
            if(s[i]=='a') a--;
            else if(s[i]=='b') b--;
            else c--;
            i++;
        }
        return ans;
    }
};