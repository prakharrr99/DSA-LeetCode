class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1; int check=1; int one=0; int zeroes=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) one=1;
            if(nums[i]!=0) product*=nums[i];
            else{
                zeroes++; check=0;
            }
        }
        if(product==1 && one==0) product=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(check==0 && zeroes==1){
                if(nums[i]!=0) ans.push_back(0);
                else ans.push_back(product);
            }
            else if(check==0 && zeroes>1){
                ans.push_back(0);
            }
            else{
                ans.push_back(product/nums[i]);
            }
        }
        return ans;
    }
};