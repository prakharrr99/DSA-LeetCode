class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        int mid=i+(j-i)/2;
        while(j>=i){
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) i++;
            else j--;
            mid=i+(j-i)/2;
        }
        return i;
    }
};