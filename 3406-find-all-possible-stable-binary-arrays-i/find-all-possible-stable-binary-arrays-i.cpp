class Solution {
public:
    int M=1e9+7;
    int dp[201][201][2];
    int solve(int zero,int one,bool oneused,int limit){
        if(zero==0 && one==0) return 1;

        if(dp[zero][one][oneused]!=-1){
            return dp[zero][one][oneused];
        }
        int result=0;
        if(oneused){
            // then go with 0
            for(int i=1;i<=min(zero,limit);i++){
                result=(result+solve(zero-i,one,false,limit))%M;
            }
        }
        else{
            //go with 1;
            for(int i=1;i<=min(one,limit);i++){
                result=(result+solve(zero,one-i,true,limit))%M;
            }
        }
        return dp[zero][one][oneused]=result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int zeroes=solve(zero,one,true,limit);
        int ones=solve(zero,one,false,limit);
        return (zeroes+ones)%M;
    }
};