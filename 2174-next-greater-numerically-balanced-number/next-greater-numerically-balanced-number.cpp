class Solution {
private:
    bool solve(int a){
        int arr[10]={0};
        //map<int,int> m;
        int c=a;
        while(a!=0){
            int b=a%10;
            //m[b]++;
            arr[b]++;
            a=a/10;
        }
        // for(auto it:m){
        //     if(it.first!=it.second) return false;
        // }
        while(c!=0){
            int b=c%10;
            if(b!=arr[b]) return false;
            c=c/10;
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