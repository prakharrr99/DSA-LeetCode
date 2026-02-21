class Solution {
public:
    bool prime(int a){
        if(a==0|| a==1) return false;
        else if(a==2) return true;
        for(int i=2;i<a;i++){
            if(a%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int a=i;
            int c=0;
            while(a!=0){
                if(a&1==1) c++;
                a=a>>1;
            }
            if(prime(c)) ans++;
        }
        return ans;
    }
};