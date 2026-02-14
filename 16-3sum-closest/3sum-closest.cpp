class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int a=INT_MAX; int ans=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int p=i+1; int q=nums.size()-1; int f=0;
            while(q>p){
                int s=nums[i]+nums[q]+nums[p];
                if(target==s) return s;
                else if(target>s){
                    if(abs(target-s)<a){ a=abs(target-s); ans=s;}
                    p++;
                    while(q>p && nums[p]==nums[p-1]) p++;
                }
                else{
                    if(abs(target-s)<a){ a=abs(target-s);  ans=s;}
                    q--;
                    while(q>p && nums[q]==nums[q+1]) q--;
                }
            }
        }
        return ans;
    }
};