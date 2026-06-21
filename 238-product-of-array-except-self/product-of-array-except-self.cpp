class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        for(auto it:nums) if(it==0) a++;
        if(a>1){
            vector<int> r(n,0);
            return r;
        }
        else{
            int b=1;
            for(auto it:nums){
                if(it!=0) b*=it;
            }
            if(a==1){
                vector<int> r;
                for(auto it:nums){
                    if(it==0) r.push_back(b);
                    else r.push_back(0);
                }
                return r;
            }
            else{
                vector<int> r;
                for(auto it:nums){
                    r.push_back(b/it);
                }
                return r;
            }
        }
        return {};
    }
};