class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0; int j=numbers.size()-1;
        vector<int> ans;
        while(j>i){
            if(numbers[i]+numbers[j]==target){
                ans.push_back(1+i);
                ans.push_back(1+j);
                break;
            }
            else if(numbers[i]+numbers[j]>target) j--;
            else i++;
        }
        return ans;
    }
};