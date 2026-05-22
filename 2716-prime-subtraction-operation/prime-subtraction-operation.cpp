class Solution {
public:

    bool primeSubOperation(vector<int>& nums) {
        int N=1000+1;
        vector<bool> prime(N,true);
        prime[0]=prime[1]=false;

        vector<int> p[N];
        
        for(int i=2;i<=1000;i++){
            if(prime[i]){
                for(int j=i+1;j<=1000;j++){
                    p[j].push_back(i);
                }
                for(int j=2*i;j<=N;j+=i){
                    prime[j]=false;
                }
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            
            if(nums[i]>=nums[i+1]){
                int a=0;
                for(int j=0;j<p[nums[i]].size();j++){
                    if(nums[i]-p[nums[i]][j]<nums[i+1]){
                        nums[i]=nums[i]-p[nums[i]][j];
                        a=1;
                        break;
                    }
                }
                if(a==0) return false;
            }
        }
        return true;
    }
};