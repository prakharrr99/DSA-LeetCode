class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int m=0;
        int p=n;
        while(n!=0){
            m=m<<1;
            m=m|1;
            n=n>>1;
        }
        m=m^p;
        return m;
    }
};