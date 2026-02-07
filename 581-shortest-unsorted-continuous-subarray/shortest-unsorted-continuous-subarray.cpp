class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int j=0;
        int i=-1;
        int a=0;
        int m=INT_MIN;
        int mi=INT_MAX;
        int idx=-1;
        while(j<nums.size()-1){
            if(nums[j]>nums[j+1]){
                idx=j+2;
                mi=min(min(nums[j],nums[j+1]),mi);
                m=max(max(nums[j],nums[j+1]),m);
                if(i==-1){
                    a=2;
                    i=j;
                }
                else{
                    a=j-i+2;
                }
            }
            // if(m>nums[j]) a++;
            j++;
        }
        while(idx<nums.size()){
            if(m>nums[idx]) a++;
            idx++;
        }
        i--;
        while(i>=0){
            if(mi<nums[i]) a++;
            i--;
        }
        return a;
    }
};