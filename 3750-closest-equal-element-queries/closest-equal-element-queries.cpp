class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            if(m[nums[queries[i]]].size()>1){
                int mi=INT_MAX;
                vector<int>& a=m[nums[queries[i]]];
                int n=a.size();

                auto it=lower_bound(a.begin(),a.end(),queries[i]);
                int index=it-a.begin();

                int b=(index-1+n)%n;
                int f=(index+1)%n;

                b=a[b];
                f=a[f];
                index=a[index];

                int p=nums.size();
                mi=min(mi,(f-index+p)%p);
                mi=min(mi,(index-b+p)%p);

                ans.push_back(mi);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};