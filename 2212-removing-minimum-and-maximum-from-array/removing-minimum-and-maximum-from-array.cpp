class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int id1=min_element(nums.begin(),nums.end())-nums.begin();
        int id2=max_element(nums.begin(),nums.end())-nums.begin();

        int n=nums.size();
        int ans1=max(id1,id2)+1;
        int ans2=max(n-id1,n-id2);

        int ans3=min(id1,id2)+1+n-max(id1,id2);
        
        return min(ans1,min(ans2,ans3));
    }
};