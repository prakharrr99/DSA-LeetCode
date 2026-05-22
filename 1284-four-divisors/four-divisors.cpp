class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            int a=0;
            int c=0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    if(j==nums[i]/j){
                        c+=1;
                        a+=j;
                    } 
                    else{
                        c+=2;
                        a+=j;
                        a+=nums[i]/j;
                    }
                }
            }
            if(c==4) s+=a;
        }
        return s;
    }
};