class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        if(k>nums.size()) return ans;

        sort(nums.begin(),nums.end());
        int i=0; int j=0;
        while(j<nums.size() && j<k){
            j++;
        }
        j--;
        while(j<nums.size()){
            ans=min(nums[j]-nums[i],ans);
            i++; j++;
        }
        return ans;
    }
};