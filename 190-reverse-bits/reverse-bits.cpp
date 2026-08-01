class Solution {
public:
    int reverseBits(int n) {
        unsigned int a=0;

        int i=1;
        int j=31;
        while(i<=32){
            int b=n&1;
            b=b<<j;
            a=a|b;
            i++;
            n=n>>1;
            j--;
        }   
        return a;
    }
};