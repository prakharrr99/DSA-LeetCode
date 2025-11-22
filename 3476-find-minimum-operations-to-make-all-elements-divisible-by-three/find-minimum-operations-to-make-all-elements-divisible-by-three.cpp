class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%3!=0){
                int a=nums[i]%3;
                if(a==1) op=op+1;
                else if(a==2){
                    int b=nums[i]/3;
                    if((b+1)*3-nums[i]==1) op=op+1;
                    else op=op+2;
                } 
            }
        }
        return op;
    }
};