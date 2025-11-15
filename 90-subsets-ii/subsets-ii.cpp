class Solution {
private:
    void solve(set<vector<int>>& ans,vector<int> nums,int indx,vector<int>& temp){
        if(indx>=nums.size()){
            ans.insert(temp);
            return;
        }
        //exclude
        solve(ans,nums,indx+1,temp);
        //include
        temp.push_back(nums[indx]);
        solve(ans,nums,indx+1,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int indx=0;
        vector<int> temp;
        solve(ans,nums,indx,temp); 
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};