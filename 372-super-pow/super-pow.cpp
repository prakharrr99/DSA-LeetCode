class Solution {
public:
    int binary_Exponentiation(int a,int b,int M){
        int ans=1;
        while(b){
            if(b&1) ans=(1LL*ans*a)%M;
            a=(1LL*a*a)%M;
            b=b>>1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {

        // EFT_M=1337*(1-1/7)*(1-1/191)

        int EFT_M=1140;
        int M=1337;

        int power=0;
        for(int i=0;i<b.size();i++){
            if(power>EFT_M) power=(1LL*power*10+b[i])%EFT_M;
            else power=(1LL*power*10+b[i]);
        }

        return binary_Exponentiation(a,power,M);
    }
};