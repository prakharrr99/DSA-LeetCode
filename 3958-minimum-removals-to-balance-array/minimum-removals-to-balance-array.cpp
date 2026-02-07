class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0; int j=0; int c=0; int m=INT_MAX;
        while(j<nums.size()){
            while(1LL*nums[i]*k<nums[j]){
                i++;
                c=i;
            }
            c=i+nums.size()-j-1;
            // if(c!=0 || (i==0 && j==nums.size()-1)) 
                m=min(c,m);
            j++;
        }
        return m;
    }
};