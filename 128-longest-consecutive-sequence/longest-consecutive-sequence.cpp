class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        int count=1; int maxi=1;
        for(auto it=s.begin();it!=s.end();it++){
            auto iit=it;
            iit++;
            if(iit!=s.end() && *it+1==*iit){
                count++;
                maxi=max(maxi,count);
            }
            else count=1;
        }
        if(nums.size()==0) return 0;
        return maxi;
    }
};