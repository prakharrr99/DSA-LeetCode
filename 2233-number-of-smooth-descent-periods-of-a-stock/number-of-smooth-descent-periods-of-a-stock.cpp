class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int a=1; long long int ans=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]-prices[i+1]==1) a++;
            else{
                ans+=(a-1)*a/2;
                a=1;
            }
        }
        if(a!=1) ans+=(a-1)*a/2;

        ans+=prices.size();
        return ans;
    }
};