class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            string str;
            int a=0;
            while(nums[i]>0){
                if(nums[i]%2!=0 && a<25) str.push_back(char(a+'a'));
                if(a>=25){
                    break;
                }
                a++;
                nums[i]/=2;
            }
            while(nums[i]>0){
                str.push_back('z');
                nums[i]--;
            }
            reverse(str.begin(),str.end());
            ans.push_back(str);
        }
        return ans;
    }
};