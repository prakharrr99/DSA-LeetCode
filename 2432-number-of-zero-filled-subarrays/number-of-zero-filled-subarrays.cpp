class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i=0; int j=0;
        long long a=0;
        while(j<nums.size()){
            while(j<nums.size() && nums[j]==0){
                a+=j-i+1;
                j++;
            }
            // if(nums[j])
            j++;
            i=j;
        }
        return a;
    }
};