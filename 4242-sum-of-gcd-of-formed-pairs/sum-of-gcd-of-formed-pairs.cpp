class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> m;
        int a=INT_MIN;
        for(int i=0;i<nums.size();i++){
            a=max(a,nums[i]);
            m.push_back(a);
        }
        vector<int> p;
        for(int i=0;i<m.size();i++){
            int k=__gcd(m[i], nums[i]);
            p.push_back(k);
        }
        sort(p.begin(),p.end());

        long long ans=0;
        for(int i=0,j=p.size()-1;j>i;i++,j--){
            ans=ans+__gcd(p[i],p[j]);
        }

        return ans;
        
    }
};