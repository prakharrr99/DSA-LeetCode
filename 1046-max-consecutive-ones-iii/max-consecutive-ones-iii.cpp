class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int one=0;
        int len=0;
        int i=0; int j=0;
        while(j<nums.size()){
            if(nums[j]==1) one++;
            if(j-i+1-one<=k){
                j++;
            }
            else{
                len=max(len,j-i);
                if(nums[i]==1) one--;
                i++;
            }
        }
        len=max(len,j-i);
        return len;
    }
};