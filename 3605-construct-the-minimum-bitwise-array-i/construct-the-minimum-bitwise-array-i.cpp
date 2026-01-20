class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i];j++){
                int b=j+1;
                int a=j|b;
                if(a==nums[i]){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
};