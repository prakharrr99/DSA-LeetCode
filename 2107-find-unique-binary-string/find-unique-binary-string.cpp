class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string ans;
        string ans2;
        for(int i=0;i<n;i++){
            ans.push_back(nums[i][i]);  
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1') ans[i]='0';
            else ans[i]='1';
        }
        return ans;
    }
};