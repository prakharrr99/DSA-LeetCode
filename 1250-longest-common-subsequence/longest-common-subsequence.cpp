class Solution {
public:
    int solve(string& text1,string& text2,int idx1,int idx2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0) return 0;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(text1[idx1]==text2[idx2]) return dp[idx1][idx2]=1+solve(text1,text2,idx1-1,idx2-1,dp);

        return  dp[idx1][idx2]=max(solve(text1,text2,idx1-1,idx2,dp),solve(text1,text2,idx1,idx2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));


        int a=0;
        for(int i=0;i<text1.size();i++){
            if(text1[i]==text2[0]){
                dp[i][0]=1;
                a=1;
            }
            else if(a==1) dp[i][0]=1;
            else dp[i][0]=0;
        }
        a=0;
        for(int i=0;i<text2.size();i++){
            if(text1[0]==text2[i]){
                dp[0][i]=1;
                a=1;
            }
            else if(a==1) dp[0][i]=1;
            else dp[0][i]=0;
        }

        
        for(int i=1;i<text1.size();i++){
            for(int j=1;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //PRINTING THE LCS
        string str;
        int i=text1.size(); int j=text2.size();
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                str.push_back(text1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
        reverse(str.begin(),str.end());
        cout<<str<<endl;

        return dp[text1.size()-1][text2.size()-1];

        return solve(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};