class Solution {
private:
    long long solve(vector<int>& nums, int k){
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++) m=max(m,nums[i]);
        int i=0; int j=0; int count=0;
        long long ans=0;
        while(j<nums.size()){
            if(nums[j]==m) count++;
            while(count>k){
                if(nums[i]==m) count--;
                i++;
            }
            if(count<=k) ans+=(j-i+1);
            j++;
        }
        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long p=nums.size()*(nums.size()+1)/2;
        if(k==0) return p;
        long long q=solve(nums,k-1);
        return p-q;
    }
};