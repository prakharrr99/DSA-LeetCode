class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int o=n*n;
        int e=n*n+n;
        return gcd(o,e);
    }
};