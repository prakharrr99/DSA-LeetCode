class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,vector<int>> m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        
        while(j>i){
            int s=nums[i]+nums[j];
            if(s==target){
                int a=m[nums[i]][0];
                int b=m[nums[j]][0];
                if(a==b) b=m[nums[j]][1];
                return {a,b};
            }
            else if(s>target) j--;
            else i++;
        }
        return {};
    }
};