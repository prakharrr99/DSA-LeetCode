class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> close;
        close.push_back(1);
        for(int i=1;i<nums.size()-1;i++){
            int a=nums[i-1];
            int b=nums[i+1];
            if(a==b) close.push_back(i-1);
            else{
                int c=abs(nums[i]-nums[i-1]);
                int d=abs(nums[i]-nums[i+1]);
                if(c>d){
                    close.push_back(i+1);
                }
                else close.push_back(i-1);
            }
        }
        close.push_back(nums.size()-2);

        vector<long long> p(nums.size(),0);
        p[0]=0;
        for(int i=1;i<nums.size();i++){
            if(close[i-1]==i) p[i]=p[i-1]+1;
            else p[i]=p[i-1]+abs(nums[i]-nums[i-1]);
        }
        vector<long long> s(nums.size(),0);
        s[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(close[i+1]==i) s[i]=s[i+1]+1;
            else s[i]=s[i+1]+abs(nums[i+1]-nums[i]);
        }

        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l<r){
                ans.push_back(p[r]-p[l]);
            }
            else{
                ans.push_back(s[r]-s[l]);
            }
        }
        return ans;
    }
};