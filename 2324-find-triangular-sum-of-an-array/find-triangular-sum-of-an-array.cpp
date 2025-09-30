class Solution {
public:
    int triangularSum(vector<int>& nums) { // USE RECURSION

        if(nums.size()==1) return nums[0];

        vector<int> newnum(nums.size()-1,0);
        for(int i=0;i<newnum.size();i++){
            newnum[i]=(nums[i]+nums[i+1])%10;
        }

        return triangularSum(newnum);
    }
};