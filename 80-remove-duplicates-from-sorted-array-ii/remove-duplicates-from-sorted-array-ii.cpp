class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                m[nums[i]]=0;
            }
        }
        m[nums[nums.size()-1]]=0;
        int i=0; int j=0;
        while(j<nums.size()){
            if(m[nums[j]]<2){
                m[nums[j]]++;
                swap(nums[i++],nums[j]);
            }
            j++;
        }
        return i;
    }

};