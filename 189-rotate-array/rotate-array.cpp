class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size()) k=k-(k/nums.size())*nums.size();
        if(k==0) return;

        vector<int> a(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            a[(i+k)%nums.size()]=nums[i];
        }
        nums=a;
    }
};