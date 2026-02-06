class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[j]!=nums[i]){
                j++;
                swap(nums[i],nums[j]);
            }
        }
        return j+1;
        // vector<int> ans;
        // int j=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(j!=-1 && ans[j]!=nums[i]){
        //         ans.push_back(nums[i]);
        //         j++;
        //     }   
        //     else if(j==-1){
        //         ans.push_back(nums[i]);
        //         j++;
        //     }
        // }
        
        // nums=ans;
        // return ans.size();
        
    }
};