class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){ j=i; break;}
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        int i;
        if(j==0) return nums;
        else if(j==-1){ 
            j=nums.size()-1;
            i=nums.size();
        }
        else{
            i=j; j--;
        }
        vector<int> ans;
        
        while(i<nums.size() && j>=0){
            if(nums[i]>nums[j]) ans.push_back(nums[j--]);
            else ans.push_back(nums[i++]);
        }
        while(i<nums.size()){
            ans.push_back(nums[i++]);
        }
        while(j>=0){
            ans.push_back(nums[j--]);
        }
       
        return ans;

        // for(int i=0;i<nums.size();i++){
        //     ans.push_back(nums[i]*nums[i]);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
    }
};