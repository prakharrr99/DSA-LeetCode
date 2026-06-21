class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;

        //1
        sort(nums.begin(),nums.end());
        int a=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]==nums[i-1]+1){
                a++;
            }
            else{
                ans=max(ans,a);
                a=1;
            }
        }
        return max(ans,a);

        //2
        // unordered_map<int,int> m;
        // for(auto it:nums) m[it]=1;

        // int ans=1;
        // for(int i=0;i<nums.size();i++){
        //     int a=nums[i]+1;
        //     int b=1;
        //     while(m.find(a)!=m.end()){
        //         a++;
        //         b++;
        //     }
        //     ans=max(ans,b);
        // }
        // return ans;
    }
};