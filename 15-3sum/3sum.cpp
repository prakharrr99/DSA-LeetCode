class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> a;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int p=i+1; int q=nums.size()-1;
            while(q>p){
                int s=nums[i]+nums[p]+nums[q];
                if(s==0){
                    a.push_back({nums[i],nums[p],nums[q]});
                    p++; q--;
                    while(q>p && nums[p]==nums[p-1]) p++;
                    while(q>p && nums[q]==nums[q+1]) q--;

                }
                else if(s>0) q--;
                else p++;
            }
        }
        return a;
    }
};