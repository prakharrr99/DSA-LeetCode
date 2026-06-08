class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    
        vector<int> small;
    
        vector<int> large;
        
        vector<int> equal;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot)  large.push_back(nums[i]);
            else if(nums[i]==pivot) equal.push_back(nums[i]);
            else small.push_back(nums[i]);
        }
        int m=0;
        for(int i=0;i<small.size();i++){
            nums[m++]=small[i];
        }
        for(int i=0;i<equal.size();i++){
            nums[m++]=equal[i];
        }
        for(int i=0;i<large.size();i++){
            nums[m++]=large[i];
        }
        return nums;
    }
};