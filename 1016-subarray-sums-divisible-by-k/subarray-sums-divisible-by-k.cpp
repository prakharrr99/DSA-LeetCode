class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int s=0;
        unordered_map<int,int> m;
        m[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            int rem=s%k;
            if(rem<0) rem=rem+k; // because comp doesn't store -ve if it come , we have to make the remainder +ve as followed in maths
            ans+=m[rem];
            m[rem]++;
        }
        return ans;
    }
};