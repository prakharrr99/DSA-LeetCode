class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f0=0;
        int n=nums.size();
        int s=0;
        for(int i=0;i<nums.size();i++){
            f0+=i*nums[i];
            s+=nums[i];
        }
        
        int ans=f0;
        for(int i=1;i<nums.size();i++){
            int temp=f0+s-n*nums[n-i];
            ans=max(ans,temp);
            f0=temp;
        }
        return ans;
    }
};