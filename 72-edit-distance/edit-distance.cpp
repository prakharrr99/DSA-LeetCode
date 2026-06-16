class Solution {
public:
    int f(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=f(s1,s2,i-1,j-1,dp);
        int in=f(s1,s2,i,j-1,dp)+1;
        int d=f(s1,s2,i-1,j,dp)+1;
        int r=f(s1,s2,i-1,j-1,dp)+1;

        return dp[i][j]=min(in,min(d,r));
    }
    int minDistance(string word1, string word2) {
        if(word1==word2) return 0;
        if(word1.size()==0) return word2.size();

        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return f(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};