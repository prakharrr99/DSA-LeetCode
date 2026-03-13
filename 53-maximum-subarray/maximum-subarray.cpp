class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int s=0; int maxi=INT_MIN; 
        // int start=-1; int end=-1; // IF WE WANT TO PRINT THE SUB-ARRAY
        // for(int i=0;i<nums.size();i++){
        //     if(s==0) start=i;
        //     s+=nums[i];
        //     if(maxi<s){
        //         maxi=s;
        //         end=i;
        //     }
        //     if(s<0) s=0;
        // }
        // return maxi;
        //KADANE's ALGO

        //PRATYUSH NARAIN

        int ans=nums[0];
        int start=0; int end=0;
        int best_ending=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=best_ending+nums[i];
            if(v1>v2){
                start=i;
            }
            best_ending=max(v1,v2);
            if(ans<best_ending){
                end=i;
            }
            ans=max(ans,best_ending);
        }
        //ans=max(ans,best_ending);
        // if(ans<0) ans=0;
        return ans;
    }
};