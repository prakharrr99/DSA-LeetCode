class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int a=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]<nums[i+1]) a++;
            else break;
            i++;
        }
        if(a==0) return false;
        a=0;
        while(i<nums.size()-1){
            if(nums[i]>nums[i+1]) a++;
            else break;
            i++;
        }
        if(a==0) return false;
        a=0;
         while(i<nums.size()-1){
            if(nums[i]<nums[i+1]) a++;
            else break;
            i++;
        }
        if(a==0) return false;
        if(i!=nums.size()-1) return false;
        return true;
    }
};