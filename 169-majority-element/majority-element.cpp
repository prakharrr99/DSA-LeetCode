class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        n=n/2;
        //Moore voting algorithm
        // this is valid only if an element appears more than n/2 times
        int count=0;
        int candidate=0;
        for(auto it:nums){
            if(count==0){
                candidate=it;
            }
            if(it==candidate) count++;
            else count--;
        }
        return candidate;
    }
};