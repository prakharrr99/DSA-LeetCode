class Solution {
public:
    int largestPrime(int n) {

        vector<bool> prime(n+8,1);
        prime[0]=prime[1]=false;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                for(int j=i*2;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }

        int ans=0;
        long long s=0;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                s+=i;
                if(s>n) break;
                if(prime[s]) ans=s;
            }
        }
        return ans;
    }
};