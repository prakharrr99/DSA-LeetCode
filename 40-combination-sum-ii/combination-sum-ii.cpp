class Solution {
private:
    void solve(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& a,int target,int s,int id){

        if(id>=candidates.size() || s>=target){
            if(s==target) ans.push_back(a);
            return;
        }
        
        for(int i=id;i<candidates.size();i++){
            if(i>id && candidates[i]==candidates[i-1]) continue;
            if(s>target) break;
            a.push_back(candidates[i]);
            s+=candidates[i];
            solve(candidates,ans,a,target,s,i+1);
            a.pop_back();
            s-=candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> a;
        int s=0;
        solve(candidates,ans,a,target,s,0);

        return ans;
    }
};