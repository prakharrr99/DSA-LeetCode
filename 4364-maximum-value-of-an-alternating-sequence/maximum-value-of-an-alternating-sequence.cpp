class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        
        long long ans=s+1LL*m*(n/2);
        ans=ans-(n/2-1);
        return ans;
    }
};