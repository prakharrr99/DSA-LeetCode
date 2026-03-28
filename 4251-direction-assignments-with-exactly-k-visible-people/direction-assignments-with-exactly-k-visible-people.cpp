class Solution {
public:
    int M=1e9+7;
    int factorial(int n){
        int f=1;
        for(int i=1;i<=n;i++){
            f=(1LL*f%M*i%M)%M;
        }
        return f;
    }
    long long power(long long n,long long m){
        long long ans = 1;
        n = n%M;   
        while(m>0){
            if(m%2 == 1) ans = (ans*n)%M;
            n = (n*n)%M;
            m = m/2;
        }
        return ans;
    }
    long long inverse(long long d){
        return power(d,M -2);
    }
    int countVisiblePeople(int n, int pos, int k) {
        
        if(k==0) return 2;

        int ans=1;
        int a=factorial(n-1);
        int b=factorial(k);
        int c=factorial(n-1-k);
        
        int mod_inv1=inverse(b);
        int mod_inv2=inverse(c);
     
        return (1LL*a%M*mod_inv1%M*mod_inv2%M*2)%M;
    }
};