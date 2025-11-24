class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0;      // always stays between 0 and 4

        for (int bit : nums) {
            num = (num * 2 + bit) % 5;  // prevents overflow
            ans.push_back(num == 0);
        }

        return ans;
    }
};
