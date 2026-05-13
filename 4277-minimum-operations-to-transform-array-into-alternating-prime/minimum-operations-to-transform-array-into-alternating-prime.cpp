class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2;i<n;i++) if(n%i==0) return false;
        return true;
    }
    int minOperations(vector<int>& nums) {
        

        int n = 1000000;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> e;
        vector<int> o;
        for(int i=0;i<nums.size();i++){
            if(i&1) o.push_back(nums[i]);
            else e.push_back(nums[i]);
        }

        int ans=0;
        for(int i=0;i<o.size();i++){
            // if(o[i]==1){
            //     ans+=3;
            //     continue;
            // }
            if(o[i]==2){
                ans+=2;
                continue;
            }
            if(isPrime[o[i]]) ans++;
        }
        
        for(int i=0;i<e.size();i++){
            if(isPrime[e[i]]) continue;

            for(int j=e[i];j<=n;j++){
                if(isPrime[j]){
                    ans+=abs(j-e[i]);
                    break;
                }
            }
        }
        return ans;
    }
};