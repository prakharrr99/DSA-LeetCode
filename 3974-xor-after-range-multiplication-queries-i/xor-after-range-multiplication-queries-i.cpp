class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int M=1e9+7;
        for(int j=0;j<queries.size();j++){
            int idx=queries[j][0];
            while(idx<=queries[j][1]){
                nums[idx]=(1LL*nums[idx]%M*queries[j][3]%M)%M;
                idx+=queries[j][2];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};