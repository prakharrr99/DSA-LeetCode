class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<int>& a,int id,int s,vector<vector<int>>& ans){
        if(id>=candidates.size() || s>=target){
            if(s==target){
                ans.push_back(a);
                return;
            }
            return;
        }

        s+=candidates[id];
        a.push_back(candidates[id]);
        solve(candidates,target,a,id,s,ans);
        a.pop_back();
        s-=candidates[id];

        solve(candidates,target,a,id+1,s,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int s=0;
        vector<int> a;
        solve(candidates,target,a,0,s,ans);
        return ans;
    }
};