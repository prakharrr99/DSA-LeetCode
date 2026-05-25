class Solution {
public:
    bool increasing(vector<int>& nums,int id){
        int a=1;
        for(int i=id+1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1) a++;
        }
        int b=1;
        for(int i=1;i<id;i++){
            if(nums[i]-nums[i-1]==1) b++;
        }
        return a+b==nums.size();
    }
    bool decreasing(vector<int>& nums,int id){
        int a=1;
        for(int i=id+1;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1]==1) a++;
        }
        int b=1;
        for(int i=id-1;i>=0;i--){
            if(nums[i]-nums[i+1]==1) b++;
        }
        return a+b==nums.size();
    }
    int minOperations(vector<int>& nums) {
        
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        if(sorted==nums) return 0;
        vector<int> vv=nums;
        reverse(vv.begin(),vv.end());
        if(vv==sorted) return 1;

        int id=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                id=i; break;
            }
        }
        if(increasing(nums,id)){
            int l1=nums.size()-id;
            int l2=nums.size()-l1;
            return min(l2,1+l1+1);
        }
        if(decreasing(nums,id)){
            int l1=1+id;
            int l2=nums.size()-l1;
            return min(l1+1,1+l2);
        }   
        return -1;
    }
};