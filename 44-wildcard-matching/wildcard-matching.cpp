class Solution {
public:
    bool f(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        // SEE PREVIOUS SUBMITTED CODE FOR ORIGINAL 
        // THIS IS SHIFT INDEXING

        if(i==0 && j==0) return true;

        if(i==0 && j>=1){
            for(int a=1;a<=j;a++){
                if(p[a-1]!='*') return false;
            }
            return true;
        }

        if(j==0 && i>=1) return false;

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?') {
            return dp[i][j]=f(s,p,i-1,j-1,dp);
        }
        if(p[j-1]=='*'){
            return dp[i][j]=f(s,p,i-1,j,dp)|f(s,p,i,j-1,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));

        dp[0][0]=1;
        int b=0;
        for(int i=1;i<p.size();i++){
            if(p[i]=='*') dp[0][i]=1;
            else{
                b=1;
            }
            if(b==1) dp[0][i]=0;
        }
        for(int i=1;i<s.size();i++){
            dp[i][0]=false;
        }

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                int one=0;
                int two=0;
                if(s[i-1]==p[j-1] || p[j-1]=='?') {
                    one=f(s,p,i-1,j-1,dp);
                }
                if(p[j-1]=='*'){
                   two=f(s,p,i-1,j,dp)|f(s,p,i,j-1,dp);
                }
                dp[i][j]=one|two;
            }
        }
        dp[s.size()][p.size()];
        return f(s,p,s.size(),p.size(),dp);
    }
};