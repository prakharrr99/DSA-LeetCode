class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long score=0;
        int idx=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        priority_queue<int> pq;
        for(int i=0;i<=idx;i++){
            pq.push(nums[i]);
            if(s[i]=='1'){
                score+=pq.top();
                pq.pop();
            }
        }
        
        return score;
    }
};