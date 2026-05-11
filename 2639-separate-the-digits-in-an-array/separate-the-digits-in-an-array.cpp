class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            vector<int> a;
            while(nums[i]!=0){
                a.push_back(nums[i]%10);
                nums[i]/=10;
            }
            reverse(a.begin(),a.end());
            for(int i=0;i<a.size();i++){
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};