class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0; int maxi=INT_MIN; 
        int start=-1; int end=-1; // IF WE WANT TO PRINT THE SUB-ARRAY
        for(int i=0;i<nums.size();i++){
            if(s==0) start=i;
            s+=nums[i];
            if(maxi<s){
                maxi=s;
                end=i;
            }
            if(s<0) s=0;
        }
        return maxi;
    }
};