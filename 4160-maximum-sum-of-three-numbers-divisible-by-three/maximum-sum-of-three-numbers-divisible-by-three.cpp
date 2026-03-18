class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> r0;
        vector<int> r1;
        vector<int> r2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0) r0.push_back(nums[i]);
            else if(nums[i]%3==1) r1.push_back(nums[i]);
            else r2.push_back(nums[i]);
        }
        int ans=0;
        if(r1.size()>2) ans=max(r1[r1.size()-1]+r1[r1.size()-2]+r1[r1.size()-3],ans);
        if(r2.size()>2) ans=max(r2[r2.size()-1]+r2[r2.size()-2]+r2[r2.size()-3],ans);
        if(r0.size()>2) ans=max(r0[r0.size()-1]+r0[r0.size()-2]+r0[r0.size()-3],ans);

        if(r1.size()!=0 && r2.size()!=0 && r0.size()!=0) ans=max(ans,r0[r0.size()-1]+r1[r1.size()-1]+r2[r2.size()-1]);
        return ans;
    }
};