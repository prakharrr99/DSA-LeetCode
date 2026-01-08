class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> p;
        int j=0;
        int s=0; int ans=0;
        while(j<nums.size()){
            if(nums[j]==0) s+=(-1);
            else s+=1;
            p.push_back(s);
            j++;
        }
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(p[i]==0) ans=max(ans,i+1);
            if(m[p[i]]==0){
                if(i==0) m[p[i]]=INT_MAX;
                else m[p[i]]=i;
            }
            else{
                if(m[p[i]]==INT_MAX) ans=max(i-0,ans);
                else ans=max(i-m[p[i]],ans);
            }
        }
        return ans;
    }
};