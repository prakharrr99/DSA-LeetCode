class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s=0;
        unordered_map<int,int> m;
        int ans=0;
        m[0]=1; // jab array khali tha tab ham ek baar dhek chuke hai 0
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            ans+=m[s-k];         
            m[s]++;
        }
        return ans;
    }
};