class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        unordered_map<int,int> m1;
        for(auto it:m){
            if(it.second>1) m1[it.first]=it.second;
        }

        int op=0;
        if(m1.size()==0) return op;

        for(int i=0;i<nums.size();i+=3){
            int j=i;
            while(j<i+3 && j<nums.size()){
                if(m[nums[j]]>1){
                    m1[nums[j]]--;
                    if(m1[nums[j]]==1) m1.erase(nums[j]);
                }
                m[nums[j]]--;
                j++;
            }
            op++;
            if(m1.size()==0) return op;
        }
        return op;
    }
};