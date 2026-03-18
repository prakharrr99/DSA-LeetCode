class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            nums.push_back(nums[i]);
        }
        vector<int> ans(nums.size(),-1);

        for(int i=0;i<nums.size();i++){
            while(s.size()!=0 &&  nums[s.top()]<nums[i]){
                ans[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(ans.size()!=n) ans.pop_back();
        return ans;
    }
};