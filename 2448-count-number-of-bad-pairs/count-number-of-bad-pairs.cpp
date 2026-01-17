class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        long long ans=nums.size()*(nums.size()-1)/2;
        long long notbad=0;
        for(int i=0;i<nums.size();i++){
            long long need=nums[i]-i;
            if(m.find(need)!=m.end()){
                notbad+=m[need];
            }
            m[need]++;
        }
        return ans-notbad;
    }
};