class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        int i=0;
        int j=0;
        for(j=0;j<k;j++){
            while(!q.empty() && nums[q.back()]<nums[j]) q.pop_back();
            if(q.empty() || nums[q.back()]>=nums[j]){
                q.push_back(j);
            }
        }
        ans.push_back(nums[q.front()]);
        i++;
        while(j<nums.size()){
            while(!q.empty() && i>q.front()) q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[j]) q.pop_back();
            if(q.empty() || nums[q.back()]>=nums[j]){
                q.push_back(j);
            }
            ans.push_back(nums[q.front()]);
            j++;
            i++;
        }
        return ans;
    }
};