class Solution {
public:
    int solve(vector<int>& nums, int target,int i){
        if(i==0){
            if(target==0 && nums[0]==0) return 2;
            else if(target==nums[0] || target==(-1)*nums[0]) return 1;
            return 0;
        }

        return solve(nums,target-nums[i],i-1)+solve(nums,target+nums[i],i-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums,target,nums.size()-1);
    }
};