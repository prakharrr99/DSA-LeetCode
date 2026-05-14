class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return false;

        for(int i=0;i<nums.size();i++){
            if(i!=nums.size()-1 && i+1!=nums[i]) return false;
            if(i==nums.size()-1 && nums[i]!=nums[i-1]) return false;
           
        }

        return true;
    }
};