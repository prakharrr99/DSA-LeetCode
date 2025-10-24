class Solution {
private:
    bool solve(int a){
        map<int,int> m;
        while(a!=0){
            int b=a%10;
            m[b]++;
            a=a/10;
        }

        for(auto it:m){
            if(it.first!=it.second) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        int a=n+1;

        while(!solve(a)){
            a++;
        }
        return a;
    }
};