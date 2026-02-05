class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> r(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                r[i]=nums[i];
            }
            else if(nums[i]>0){
                int k=nums[i]%n;
                r[i]=nums[(i+k)%n];
            }
            else{
                int k=abs(nums[i])%n;
                r[i]=nums[(i-k+n)%n];
            }
        }
        return r;
    }
};