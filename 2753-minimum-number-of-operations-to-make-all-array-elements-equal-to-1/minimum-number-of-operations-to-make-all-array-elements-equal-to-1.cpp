class Solution {
private:
    int hcf(int a,int b){
        while(a!=0){ // b>a
            int temp=a;
            a=b%a;
            b=temp;
        }
        return b;
    }
public:
    int minOperations(vector<int>& nums) {
        int one=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) one++;
        }
        if(one!=0) return nums.size()-one;

        int a=INT_MAX;  // the question doesn t say we can only use those two elements
        for(int i=0;i<nums.size();i++){
            int g=nums[i];
            for(int j=i+1;j<nums.size();j++){
                g=hcf(g,nums[j]);
                if(g==1){
                    a=min(a,j-i+1);
                    break;
                }
            }
        }

        if(a==INT_MAX) return -1;
        return a-1+nums.size()-1;
    }
};