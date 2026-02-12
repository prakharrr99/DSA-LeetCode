class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int j=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(j==-1 && nums[i]<0) j=i+1;
            if(nums[i]<0){
                ans.push_back(abs(nums[i]));
            }
        }

        if(ans.size()==0){
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]*nums[i];
            }
            return nums;
        }

        int i=0; int k=j;
        vector<int> a;
        while(i<ans.size() && j<nums.size()){
            if(ans[i]>nums[j]) a.push_back(nums[j++]);
            else a.push_back(ans[i++]);
        }
        while(i<ans.size()){
            a.push_back(ans[i++]);
        }
        while(j<nums.size()){
            a.push_back(nums[j++]);
        }
        for(int i=0;i<a.size();i++){
            a[i]=a[i]*a[i];
        }
        return a;

        // for(int i=0;i<nums.size();i++){
        //     ans.push_back(nums[i]*nums[i]);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
    }
};