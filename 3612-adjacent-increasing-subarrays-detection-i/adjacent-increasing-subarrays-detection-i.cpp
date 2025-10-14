class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<=nums.size()-2*k;i++){
            int p=i,q=i+k;
            
            int a=0;
            while(p<i+k-1){
                if(nums[p]>=nums[p+1]){
                    a=1; break;
                }
                p++;
            }
            if(a==1) continue;
            while(q<2*k+i-1){
                if(nums[q]>=nums[q+1]){
                    a=1; break;
                }
                q++;
            }
            if(a==0) return true;
        }
        return false;
    }
};