class Solution {
private:
    int bit(int n){
        int a=0;
        while(n>0){
            if(n&1==1) a++;
            n=n>>1;
        }
        return a;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(bit(i));
        }
        return ans;
    }
};