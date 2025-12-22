class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        if(nums.size()<4) return ans;

        for(int i=0;i<nums.size()-3;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int p=j+1; int q=nums.size()-1;
                while(q>p){
                    long long s=1LL*nums[i]+nums[j]+nums[p]+nums[q];
                    if(s==target){
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;q--;
                        while(p<q && nums[p]==nums[p-1]){
                            p++;
                        }   
                        while(p<q && nums[q]==nums[q+1]){
                            q--;
                        }
                    }
                    else if(s>target) q--;
                    else p++;   
                }
            }
        }
        return ans;
    }
};