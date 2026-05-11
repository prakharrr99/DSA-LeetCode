class Solution {
public:
    int min_in_rotated_sorted(vector<int>& nums){
        if(nums.size()==1) return 0;
        if(nums[0]<nums[nums.size()-1]) return 0;
        int ans=-1;

        int low=0;
        int high=nums.size()-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(nums[0]<=nums[mid]){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        }
        int low=0; int high=0;
        if(nums[0]<=target){
            low=0;
            high=min_in_rotated_sorted(nums)-1;
        }
        else{
            low=min_in_rotated_sorted(nums);
            high=nums.size()-1;
        }
        
        if(nums[0]<nums[nums.size()-1]){ low=0; high=nums.size()-1;}// WHEN ARRAY IS ALREADY SORTED

        while(high>=low){
            int mid=low+(high-low)/2;
            if(target==nums[mid]) return mid;
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};