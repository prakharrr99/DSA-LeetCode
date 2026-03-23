class Solution {
public:
    int findMin(vector<int>& nums) {

        if(nums[nums.size()-1]>nums[0]) return nums[0];
        if(nums.size()==1) return nums[0];
        
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(nums[mid]>=nums[0]){
                low=mid+1;
            }
            else{
                ans=nums[mid];
                high=mid-1;
            }
        }
        return ans;
    }
};