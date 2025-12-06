class Solution {
    private:
    int pivot(vector<int>& nums){
        int i=0;int j=nums.size()-1;
        int mid=i+(j-i)/2;
        while(j>=i){
            if(nums[mid]<nums[0]) j=mid-1;
            else i=mid+1;
            mid=i+(j-i)/2;
        }
        return mid;
    }
public:
    int search(vector<int>& nums, int target) {

        int pivotindex=pivot(nums);
    
        int i; int j;
        if(target==nums[0]) return 0;
        else if(target>nums[0]) {
            i=1; j=pivotindex-1;
        } 
        else{
            i=pivotindex;
            j=nums.size()-1;
        }
        int mid=i+(j-i)/2;
        while(j>=i){
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) i=mid+1;
            else j=mid-1;
            mid=i+(j-i)/2;
        }    
        return -1;
    }
};