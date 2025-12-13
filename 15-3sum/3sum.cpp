class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            int p=i+1;int q=nums.size()-1;
            if(i!=0 && nums[i]==nums[i-1]) continue;
            while(q>p){
                if(nums[p]+nums[q]+nums[i]==0){
                    ans.push_back({nums[i],nums[p],nums[q]});
                    p++;q--;
                    while(p<q && nums[p]==nums[p-1]) p++;
                    while(p<q && nums[q]==nums[q+1]) q--;
                }
                else if(nums[p]+nums[q]+nums[i]>0) q--;
                else p++;
            }
        }
        return ans;
    }
};