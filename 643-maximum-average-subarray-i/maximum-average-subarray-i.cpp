class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0; int j=0;
        double ans=INT_MIN;
        double av=0;
        while(j<nums.size()){
            while(j-i+1>k){
                ans=max(ans,av/float(k));
                av-=nums[i];
                i++;
            }
            av+=nums[j];
            j++;
        }
        ans=max(ans,av/float(k));
        return ans;
    }
};