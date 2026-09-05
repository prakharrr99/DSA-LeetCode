class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> l;
        vector<int> h;
        int p=INT_MIN;
        for(int i=0;i<nums.size();i++){
            p=max(p,nums[i]);
            h.push_back(p);
        }
        p=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            p=min(p,nums[i]);
            l.push_back(p);
        }
        reverse(l.begin(),l.end());
        
        for(int i=0;i<nums.size();i++){
            if(h[i]-l[i]<=k) return i;
        }
        return -1;
    }
};