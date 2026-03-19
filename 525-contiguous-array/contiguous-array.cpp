class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero=0; int one=0;
        int ans=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++; // this is for counting
            else one++;

            // if(one-zero==0) ans=max(ans,i+1); //edge case

            if(m.find(one-zero)!=m.end()) ans=max(ans,i-m[one-zero]);  // if found update
            else m[one-zero]=i;     // else map with the firt index where that diff occur as we have to find the longest subarray 
            // we dont have to count

        }
        return ans;

        // find the condition
        // make green part satisfy the condition 
        // then the red part which is left will have the same output(here diff) as the whole subarray
        // map the red part if it exist then green part will also exist count it , form the longest or do whatever is required

    }
};