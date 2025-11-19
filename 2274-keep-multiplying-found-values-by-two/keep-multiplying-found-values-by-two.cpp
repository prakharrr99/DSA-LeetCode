class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int i=0; int j=nums.size()-1;

        int mid=i+(j-i)/2;
        while(j>=i){
            if(nums[mid]==original){
                original*=2;
                j=nums.size()-1;
            }
            else if(nums[mid]<original) i=mid+1;
            else j=mid-1;
            mid=i+(j-i)/2;
        }
        return original;
    }
};