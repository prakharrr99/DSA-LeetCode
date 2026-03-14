class Solution {
public:
    void solve(int n,string a,vector<string>& ans,string s){
        if(a.size()==n){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<s.size();i++){
            a.push_back(s[i]);
            solve(n,a,ans,s);// this is not about subsequences it should choose any character at a particular call until the size becomes n
            a.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        string a;
        solve(n,a,ans,"abc");

        sort(ans.begin(),ans.end());
        vector<string> p;
        for(int i=0;i<ans.size();i++){
            int b=0;
            for(int j=0;j<n-1;j++){
                if(ans[i][j]==ans[i][j+1]){
                    b=1; break;
                }
            }
            if(b==0) p.push_back(ans[i]);
        }
        if(k>p.size()) return "";
        return p[k-1];
    }
};