class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]>0) swap(nums[i++],nums[j]);
        }
        while(nums.size()!=i) nums.pop_back();

        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        if(mini!=1) return 1;
        // if(maxi-mini==nums.size()-1) return maxi+1;

       
        unordered_map<int,int> m;
        for(auto it:nums){
            m[it]=1;
        }
        int a=1;
        while(a!=maxi){
            if(m.find(a)==m.end()) return a;
            a++;
        }
        return ++a;
    }
};