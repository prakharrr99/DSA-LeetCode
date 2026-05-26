class Solution {
public:
    bool canJump(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) a++;
        }
        if(a==0) return true;
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i>ans) return false;
            
            ans=max(ans,i+nums[i]);
        }
        if(ans>=nums.size()-1) return true;
        return false;
    }
};