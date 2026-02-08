class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<int> ms;

        int l=0;
        long long a=0;
        for(int r=0;r<nums.size();r++){
            ms.insert(nums[r]);
            while(r>=l && ms.size() && 1LL*(r-l+1)*(*ms.rbegin()-*ms.begin())>k){
                ms.erase(ms.find(nums[l]));
                l++;
            }
            a+=(r-l+1);
        }
        return a;
    }
};