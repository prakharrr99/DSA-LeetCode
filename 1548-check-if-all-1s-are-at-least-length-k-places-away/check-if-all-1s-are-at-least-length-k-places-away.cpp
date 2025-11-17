class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int c=0; int a=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(a==0){
                    a++;
                    c=0;
                    continue;
                }
                else if(c<k) return false;
                else c=0;
            }
            else c++;
        }
        return true;
    }
};