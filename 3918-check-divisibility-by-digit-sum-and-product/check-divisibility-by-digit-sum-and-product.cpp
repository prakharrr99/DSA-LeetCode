class Solution {
public:
    bool checkDivisibility(int n) {
        int a=n;
        int s=0;
        int p=1;
        while(a){
            s+=a%10;
            p*=a%10;
            a=a/10;
        }
        return n%(s+p)==0;
    }
};