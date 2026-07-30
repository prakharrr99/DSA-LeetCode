class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26,0);
        int s=2;
        int c=0;
        for(auto it:word){
            if(s<=9){
                c++;
                s++;
                f[it-'a']=1;
            }
            else if(s<=17){
                c+=2;
                s++;
                f[it-'a']=1;
            }
            else if(s<=25){
                c+=3;
                s++;
                f[it-'a']=1;
            }
            else{
                c+=4;
            }
        }
        return c;
    }
};