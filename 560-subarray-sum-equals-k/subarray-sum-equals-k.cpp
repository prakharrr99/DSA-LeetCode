class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        vector<int> p;
        int i=0; int j=0;
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            p.push_back(s);
        }
        for(int i=0;i<nums.size();i++){
            if(p[i]==k) ans++;
            for(int j=i+1;j<nums.size();j++){
                if(p[j]-p[i]==k) ans++;
            }
        }
        return ans;
    }
};