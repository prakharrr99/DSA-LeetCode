class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i=0;i<pow(2,n);i++){
            ans.push_back(i);
        }

        for(int i=0;i<ans.size();i++){ // GRAY CODE IS  DOING THE(NUMBER'S RIGHT SHIFT)AND THEN XORWITH(ORIGINAL THING)
            int a= ans[i];
            ans[i]=ans[i]>>1;
            ans[i]=a^ans[i];
        }
        return ans;
    }
};