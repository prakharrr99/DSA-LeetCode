class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> b=nums;
        sort(b.begin(),b.end());
        // if(nums.size()==0) return {{}};
        // if(nums.size()==1) return {{nums[0]}};
        int c=1; int maxi=1;
        for(int i=0;i<nums.size()-1;i++){
            if(b[i]==b[i+1]) c++;
            else c=1;
            maxi=max(maxi,c);
        }
        vector<vector<int>> ans(maxi);
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) m[nums[i]]=-1;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            ans[m[nums[i]]].push_back(nums[i]);
        }
        return ans;
    }
};