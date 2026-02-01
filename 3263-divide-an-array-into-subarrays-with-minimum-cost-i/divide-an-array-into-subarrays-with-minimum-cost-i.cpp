class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini=INT_MAX;
        int mini2=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<mini){
                mini2=mini;
                mini=nums[i];
            }
            else if(mini2>nums[i]) mini2=nums[i];
        }
        return nums[0]+mini+mini2;
    }
};