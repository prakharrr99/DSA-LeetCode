class Solution {
public:
    void solve(int i,vector<int>& a,vector<vector<int>>& ans,vector<int>& nums){
        if(a.size()>=2){
            int p=0;
            for(int i=0;i<a.size()-1;i++){
                if(a[i]>a[i+1]){
                    p=1; break;
                }
            }
            if(p==0) ans.push_back(a);
        }
        if(i==nums.size()){
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            a.push_back(nums[j]);
            solve(j+1,a,ans,nums);
            a.pop_back();
        }
        // a.push_back(nums[i]);
        // solve(i+1,a,ans,nums);
        // a.pop_back();
        // solve(i+1,a,ans,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int i=0;
        vector<vector<int>> ans;
        vector<int> a;
        solve(i,a,ans,nums);

        if(ans.size()==0) return ans;
        sort(ans.begin(),ans.end());

        vector<vector<int>> g;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]) continue;
            g.push_back(ans[i]);
        }
        
        g.push_back(ans[ans.size()-1]);
        return g;
    }
};