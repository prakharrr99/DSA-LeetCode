class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int p=i;
            int q=i;
            int mini=INT_MAX;
             int maxi=INT_MIN;
            while(p>=0){
                maxi=max(maxi,nums[p--]);
            }
           
            while(q<nums.size()){
                mini=min(mini,nums[q++]);
            } 
            if((maxi-mini)<=k) return i;
        }
        return -1;
    }
    
};