class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0;
        multiset<long long> ms;
        unordered_map<int,int> m;
        for(auto it:nums){
            if(it==1) ans++;
            ms.insert(it);
            m[it]=0;
        }
        if(!(ans&1) && ans!=0) ans--;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]!=0) continue;
            if(nums[i]==1) continue;
            int temp=0;
            long long a=nums[i];
            while(ms.find(a)!=ms.end()){
                m[a]=1;
                if(ms.count(a)==1){  
                    temp++;
                    break;
                }
                else if(ms.count(a)>1){
                    temp+=2;
                    a=a*a;
                }
                else break;
            }
            if(temp&1) ans=max(ans,temp);
            else ans=max(ans,temp-1);
        }
        if(ans==0) return 1;
        return ans;
    }
};