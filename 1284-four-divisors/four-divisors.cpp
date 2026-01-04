class Solution {
private:
    int div(int a){
        int c=0; int s=0;
        for(int i=1;i<=a;i++){
            if(c>4) break;
            if(a%i==0){
                s+=i; c++;
            }
        }
        if(c==4) return s;
        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int a=div(nums[i]);
            ans+=a;
        }
        return ans;
    }
};