class Solution {
private:
    double powerr(double x,long long int n){
        if(n==0) return 1.0;

        double half=powerr(x,n/2);
        if(n%2==0) return half*half;
        else return x*half*half;
    }
public:
    double myPow(double x, int n) {
        long long a=n;
        if(n>=0)
           return powerr(x,a);

        else{
            x=1/x;
            a=-a;
            return powerr(x,a);
        }
    }
};