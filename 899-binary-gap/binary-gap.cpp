class Solution {
public:
    int binaryGap(int n) {
        int a=0;
        int b=0;
        while(n!=0){
            if(n&1==1){
                if(b!=0){
                    a=max(a,b-1);
                    b=0;
                }
                if(b==0) b=1;
            }
            if(b!=0) b++;
            n=n>>1;
        }
        return a;
    }
};