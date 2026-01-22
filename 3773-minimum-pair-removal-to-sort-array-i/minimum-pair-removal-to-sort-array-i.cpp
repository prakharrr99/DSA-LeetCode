class Solution {
public:
    bool issort(vector<int> a){
        vector<int> b=a;
        sort(a.begin(),a.end());
        return a==b;
    }
    int op=0;
    int minimumPairRemoval(vector<int>& nums) {
        if(issort(nums)) return op;
        int m=INT_MAX;
        int id=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(m>nums[i]+nums[i+1]){
                m=nums[i]+nums[i+1];
                id=i;
            }
        }
        nums[id]=m;
        for(int i=id+1;i<nums.size()-1;i++){
            nums[i]=nums[i+1];
        }
        nums.pop_back();
        op++;
        return minimumPairRemoval(nums);
    }
};