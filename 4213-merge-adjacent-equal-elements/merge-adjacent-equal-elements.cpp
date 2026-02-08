class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long > s;
        for(int i=0;i<nums.size();i++){
            long long a=nums[i];
            while(s.size() && a==s.back()){
                s.pop_back();
                a=a*2;
            }
            s.push_back(a);
        }
        return s;
    }
};