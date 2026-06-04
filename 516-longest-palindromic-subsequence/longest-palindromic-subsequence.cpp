class Solution {
public:
    int solve(string s1,string s2,int i,int j,vector<vector<int>>& dp){

        // if(i<0 || j<0) return 0;
        // WE CAN WRITE TABULATION FOR THIS 

        if(i==0 || j==0) return 0; 
        //BUT HERE WE WILL DO SHIFT INDEXING
        // IN LCS i DID IT NORMALLY WITHOUT SHIFT INDEXING

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);

        return dp[i][j]=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));

    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int n=s1.size();
        vector<vector<int>> dp(1003,vector<int>(1003,-1));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];


        return solve(s1,s,n,n,dp);
    }
};