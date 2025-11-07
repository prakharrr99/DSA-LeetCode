class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int a=9999999;
        int flag=0;
        for(int i=0;i<nums.size()-2;i++){
            int p=i+1;
            int q=nums.size()-1;
            while(q>p){
                int s=nums[i]+nums[p]+nums[q];
                if(s==target) return target;
                else if(s>target){
                    q--;
                    if(s-target<a){
                        a=s-target;
                        flag=-1;
                    }
                } 
                else{
                    p++;
                    if(target-s<a){
                        a=target-s;
                        flag=1;
                    }
                }
            }
        }
        return (flag==1)?target-a:target+a;
    }
};