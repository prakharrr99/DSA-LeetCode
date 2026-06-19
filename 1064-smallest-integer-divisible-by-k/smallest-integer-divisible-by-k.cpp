class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // vector<unsigned long long> store;
        unsigned long long ans=1;
        // store.push_back(1);
        if(ans%k==0) return 1;

        int i=0;
        while(i<=1e7){
            ans=(ans*10+1)%k;
            // store.push_back(ans);
            if(ans==0) return i+2;
            i++;
        }
        return -1;

        // int id=-1;
        // for(int i=0;i<store.size();i++){
        //     if(store[i]%k==0){
        //         id=i;
        //         break;
        //     }
        // }
        // if(id==-1) return -1;
        // int len=0;
        // unsigned long long m=store[id];
        // while(m){
        //     len++;
        //     m=m/10;
        // }
        // return len;
    }
};