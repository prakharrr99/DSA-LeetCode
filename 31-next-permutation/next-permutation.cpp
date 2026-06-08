class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> temp=nums;

        sort(temp.rbegin(),temp.rend());
        if(temp==nums){
            reverse(nums.begin(),nums.end());
            return;
        }

        int flag=-1;
        for(int i=nums.size()-1;i>=0;i--){
            int d=INT_MAX;
            int id=-1;
            for(int j=i;j<nums.size();j++){
                if(i==j) continue;
                if(d>(nums[j]-nums[i]) && (nums[j]-nums[i])>0){
                    d=min(d,nums[j]-nums[i]);
                    id=j;
                } 
            }
            if(id!=-1){
                swap(nums[i],nums[id]);
                flag=i+1;
                break;
            }
        }
        sort(nums.begin()+flag,nums.end());
    }
};