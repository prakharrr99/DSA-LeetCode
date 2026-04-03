class Solution {
public:
    int solve(vector<int>& nums, int target,int n){
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==nums[0] || target==nums[0]*(-1)) return 1;
            return 0;
        }
        return solve(nums,target+nums[n],n-1)+solve(nums,target-nums[n],n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,nums.size()-1);
    }
};