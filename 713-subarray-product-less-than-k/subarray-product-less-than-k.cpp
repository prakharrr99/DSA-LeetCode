class Solution {
private:
    int solve(vector<int>& nums, int k){
        int i=0; int j=0; int p=1; int ans=0;
        while(j<nums.size()){
            p*=nums[j];
            while(p>=k){
                p/=nums[i];
                i++;
            }
            if(p<k) ans+=(j-i+1);
            j++;
        }
        return ans;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0 || k==1) return 0;
        int p=solve(nums,k);
        return p;
    }
};