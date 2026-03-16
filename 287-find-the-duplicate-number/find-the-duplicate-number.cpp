class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[nums[0]];
        int fast=nums[nums[nums[0]]];

        // whenever [1,n] is given and size is n+1 means we can use num[i] as index it wont give out of bound 
        while(slow!=fast){ // detection of cycle means there is a duplicate
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=nums[0];// start from head
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast]; // move one one 
        }
        return fast;
    }


};