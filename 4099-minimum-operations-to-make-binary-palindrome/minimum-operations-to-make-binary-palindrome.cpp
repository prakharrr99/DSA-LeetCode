class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        vector<int> palin;
        for(int i=1;i<=5000;i++){
            int j=i;
            string s;
            while(j){
                char c=(j&1)+'0';
                s.push_back(c);
                j>>=1;
            }
            int check=0;
            for(int i=0,j=s.size()-1;j>i;i++,j--){
                if(s[i]!=s[j]){
                    check=1;
                    break;
                }
            }
            if(check==0) palin.push_back(i);
        }
        for(auto it:nums){
            int maxi=INT_MAX;
            int v=-1;
            for(auto iit:palin){
                if(maxi>abs(it-iit)){
                    maxi=abs(it-iit);
                    v=iit;
                }
                else break;
            }
            ans.push_back(abs(it-v));
        }
        return ans;
    }
};