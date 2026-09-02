class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int e=-1;
        int o=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) e=nums1[i];
            else o=nums1[i];
        }
        if(e==-1 || o==0) return true;
        return true;
    }
};