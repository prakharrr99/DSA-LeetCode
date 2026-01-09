class Solution {
private:
    int solve(vector<int>& nums, int k){
        int i=0; int j=0;
        int ans=0; int o=0;
        while(j<nums.size()){
            if(nums[j]%2!=0) o++;
            while(o>k){
                if(nums[i]%2!=0) o--;
                i++;
            }
            if(o<=k) ans+=(j-i+1);
            j++;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int p=solve(nums,k);
        if(k==0) return p;
        int q=solve(nums,k-1);
        return p-q;
    }
};