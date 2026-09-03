class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int e=INT_MAX;
        int o=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) e=nums1[i];
            else o=nums1[i];
        }
        if(e==INT_MAX || o==INT_MAX) return true;
        
        sort(nums1.begin(),nums1.end());
        if(nums1[0]%2==0){
            return false;
        }
        else{
            return true;
        }
    }
};