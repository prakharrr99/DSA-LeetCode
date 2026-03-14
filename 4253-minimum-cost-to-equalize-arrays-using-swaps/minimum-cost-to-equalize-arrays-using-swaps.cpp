class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()!=nums2.size()) return -1;
        
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]++;
            m[nums2[i]]++;
        }
        
        for(auto it:m){
            if(it.second%2!=0) return -1;
        }
        
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
            m2[nums2[i]]++;
        }

        int ans=0;
        for(auto it:m){
            if(m1[it.first]>it.second/2){
                ans+=(m1[it.first]-m2[it.first])/2;
            }
        }
        return ans;
    }
};