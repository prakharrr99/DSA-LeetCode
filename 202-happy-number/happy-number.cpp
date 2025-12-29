class Solution {
private:
    int heh(int n){
        int a=0;
        while(n!=0){
            int x=n%10;
            a+=(x*x);
            n=n/10;
        }
        return a;
    }
public:
    bool isHappy(int n) {
        if(n==1) return true;
        unordered_set<int> s;
        while(!s.count(n) && n!=1){
            s.insert(n);
            n=heh(n);
        }
        if(n==1) return true;
        return false;
    }
};