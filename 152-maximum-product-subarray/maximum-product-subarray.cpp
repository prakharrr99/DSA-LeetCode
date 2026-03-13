class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestmin=nums[0];
        int bestmax=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*bestmin;
            int v3=nums[i]*bestmax;

            bestmin=min(v1,min(v2,v3));
            bestmax=max(v1,max(v3,v2));

            ans=max(ans,bestmax);
        }
        return ans;
    }
};