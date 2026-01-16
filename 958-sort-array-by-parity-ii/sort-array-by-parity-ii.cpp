class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>o;
        vector<int>e;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) e.push_back(nums[i]);
            else o.push_back(nums[i]);
        }
        int a=0; int b=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=e[a++];
            }
            else nums[i]=o[b++];
        }
        return nums;
    }
};