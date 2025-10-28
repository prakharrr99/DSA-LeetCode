class Solution {
public:
    int countValidSelections(vector<int>& nums) {

        vector<int> sum;

        int s=nums[0];

        sum.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            s+=nums[i];
            sum.push_back(s);
        }
        int totalsum=sum[nums.size()-1];

        int count=0;
        if (nums[0] == 0) {
            if (totalsum - sum[0] == 0) count += 2;
            else if (abs(totalsum - sum[0]) == 1) count += 1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0 && sum[i-1]==(totalsum-sum[i])) count+=2;
            if(nums[i]==0 && abs(sum[i-1]-(totalsum-sum[i]))==1) count+=1;
        }

        return count;

    }
};