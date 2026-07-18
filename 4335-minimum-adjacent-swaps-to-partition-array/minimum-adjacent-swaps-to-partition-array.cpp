class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int M=1e9+7;
        int l=0;
        int m=0;
        int r=0;
        int swap=0;
        for(int i=0;i<n;i++){
            if(nums[i]<a){
                l++;
                swap=(swap+(m+r)%M)%M;
            }
            else if(nums[i]>=a && nums[i]<=b){
                m++;
                swap=(swap+r)%M;
            }
            else{
                r++;
            }
        }
        return swap;
    }
};