class Solution {
public:
    void permute(vector<int>& nums,int id,vector<vector<int>>& ans){
        if(id>=nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int i = id; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;

            used.insert(nums[i]);
            swap(nums[id], nums[i]);
            permute(nums, id + 1, ans);
            swap(nums[id], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int id=0;
        
        permute(nums,id,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};