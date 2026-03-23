class Solution {
public:
    int lb(vector<int>& nums, int target){
        int low=0; int high=nums.size()-1;
        int ans=-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int up(vector<int>& nums, int target){
        int low=0; int high=nums.size()-1;
        int ans=-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lb(nums,target),up(nums,target)};
    }
};