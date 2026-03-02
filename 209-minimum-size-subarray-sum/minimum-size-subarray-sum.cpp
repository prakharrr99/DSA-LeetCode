class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=INT_MAX;
        int i=0; int j=0;
        int s=0;
        while(j<nums.size()){
            s+=nums[j];
            while(s>=target){
                l=min(l,j-i+1);
                s-=nums[i];
                i++;
            }
            j++;
        }
        if(l==INT_MAX) return 0;
        return l;
    }
};