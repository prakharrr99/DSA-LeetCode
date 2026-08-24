class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a=1LL*min(need1,need2)*costBoth;
        if(need1>need2) a+=1LL*(need1-need2)*cost1;
        else if(need2>need1) a+=1LL*(need2-need1)*cost2;

        long long b=max(need1,need2)*1LL*costBoth;

        return min(1LL*cost1*need1+1LL*cost2*need2,min(a,b));
    }
};