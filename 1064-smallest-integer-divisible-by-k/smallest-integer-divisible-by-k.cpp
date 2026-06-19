class Solution {
public:
    int smallestRepunitDivByK(int k) {
       
        if(k%2==0 || k%5==0) return -1;
        unsigned long long ans=1%k;
        int i=1;
        while(ans!=0){
            ans=(ans*10+1)%k;
            i++;
        }
        return i;
    }
};