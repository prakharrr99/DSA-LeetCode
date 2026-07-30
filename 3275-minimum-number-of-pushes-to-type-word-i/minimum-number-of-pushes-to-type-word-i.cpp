class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26,0);
        int s=2;
        int c=0;
        for(auto it:word){
            if(f[it-'a']!=0){
                c+=f[it-'a'];
                continue;
            }
            if(s<=9){
                c++;
                s++;
                f[it-'a']=1;
            }
            else if(s<=17){
                c+=2;
                s++;
                f[it-'a']=2;
            }
            else if(s<=25){
                c+=3;
                s++;
                f[it-'a']=3;
            }
            else{
                c+=4;
                s++;
                f[it-'a']=4;
            }
        }
        return c;
    }
};