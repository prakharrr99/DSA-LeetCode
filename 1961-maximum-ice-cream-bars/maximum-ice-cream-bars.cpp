class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ic=0;
        for(auto it:costs){
            if(coins>=it){
                ic++;
                coins-=it;
            }
            else break;
        }
        return ic;
    }
};