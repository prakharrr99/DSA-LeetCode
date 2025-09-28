class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a,b,c;
        for(int i=nums.size()-1;i>1;i--){
            a=nums[i];
            b=nums[i-1];
            c=nums[i-2];
            if(a+b>c && b+c>a && c+a>b){
                return a+b+c;
            }
        }
        return 0;
    }
};