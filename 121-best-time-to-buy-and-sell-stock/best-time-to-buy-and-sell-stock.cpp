class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];
        //should start from 1;
        for(auto it:prices){
            profit=max(profit,it-mini);
            mini=min(mini,it);
        }
        return profit;
    }
};