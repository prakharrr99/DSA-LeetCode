class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0) return -1;
        
        int n=1;
        for(int i=0;i<=k;i++){
            n=(n*10+1)%k;
            if(n==0) return i+2;
        }
        return -1;

    }
};