class Solution {
public:
    int reverseBits(int n) {
        unsigned int a=0;
        int i=1;
        while(i<=32){
            int b=n&1;
            a=a|b;
            a=a<<1;
            n=n>>1;
            i++;
        }
        a=a>>1;
        return a;
    }
};