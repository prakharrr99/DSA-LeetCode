class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0; int j=0;
        vector<int> a(2,0);
        int ans=0;
        // for(int j=0;j<nums.size();j++){

        // }
        while(j<nums.size()){
            int m=INT_MIN;
            a[nums[j]]++;
            m=a[1];
            while(j-i+1-m>k){
                m=a[1];
                a[nums[i]]--;
                m=a[1];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};