class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=INT_MIN;
        for(int i=0,j=nums.size()-1;j>i;i++,j--){
            m=max(m,nums[i]+nums[j]);
        }
        return m;
    }
};