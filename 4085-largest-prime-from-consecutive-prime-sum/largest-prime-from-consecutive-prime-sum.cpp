class Solution {
public:
    bool prime(int n){
        for(int i=2;i<n;i++){
            if(n%i==0) return false;
        }
        if(n==1) return false;
        return true;
    }
    int largestPrime(int n) {
        vector<int> arr; int a=0;
        for(int i=2;i<=n;i++){
            if(prime(i)){
                if(a==0) arr.push_back(i);
                else{
                    int aa=arr[a-1]+i;
                    if(aa>n) break;
                    arr.push_back(aa);
                } 
                a++;
            }
        }
        if(arr.size()==0) return 0;
        int ans=0;
        for(int i=arr.size()-1;i>=0;i--){
            if(prime(arr[i])){
                return arr[i];
            }
        }
        return 0;
    }
};