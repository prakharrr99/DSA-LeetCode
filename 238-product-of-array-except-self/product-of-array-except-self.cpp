class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);

        int id=-1; int z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
                id=i;
            }
        }
        long long p=1;
        if(z>1) return ans;
        else{
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0) p*=nums[i];
            }
            if(z==1){
                ans[id]=p;
            }
            else{
                for(int i=0;i<nums.size();i++){
                    ans[i]=p/nums[i];
                }
            }
        }
        return ans;
    }
};