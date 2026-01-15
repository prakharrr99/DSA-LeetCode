class Solution {
private:
    void solve1(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& a,int target,int id){
        if(target<0 || id==candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(a); 
            return;
        }
        //pick
        a.push_back(candidates[id]);
        solve1(candidates,ans,a,target-candidates[id],id);
        a.pop_back();

        //skip
        solve1(candidates,ans,a,target,id+1);
    }
    void solve2(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& a,int target,int id){
        if(target<0 || id==candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(a); 
            return;
        }
        //pick
        a.push_back(candidates[id]);
        solve1(candidates,ans,a,target-candidates[id],id+1);
        a.pop_back();

        //skip
        solve1(candidates,ans,a,target,id+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        int id=0;
        vector<int> a;
        solve1(candidates,ans,a,target,id);

        // a.clear(); id=0;
        // solve2(candidates,ans,a,target,id);

        return ans;

    }
};