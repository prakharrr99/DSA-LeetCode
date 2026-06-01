class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int i=cost.size()-1;
        int j=i-1;
        int c=0;

        while(j>=0 || i>=0){
            if(i>=0) c+=cost[i];
            if(j>=0) c+=cost[j];
            i-=3;
            j-=3;
        }
        return c;
    }
};