class Solution {
public:
    int getLength(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        if(mp.size()==nums.size()) return 1;
        if(mp.size()==1) return nums.size();

        int ans=1;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> m;
            int maxi=0;
            unordered_map<int,int> f;// number of elements that have freq as x;
            for(int j=i;j<nums.size();j++){
                if(m[nums[j]]){
                    f[m[nums[j]]]--;
                }
                m[nums[j]]++;

                f[m[nums[j]]]++;
                maxi=max(maxi,m[nums[j]]);

                if(maxi%2==0 && m.size()>f[maxi] && m.size()-f[maxi]==f[maxi/2]) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};