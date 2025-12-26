class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> pre(n,0);
        if(customers[n-1]=='Y') pre[n-1]=1;
        else pre[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(customers[i]=='Y') pre[i]+=(pre[i+1]+1);
            else pre[i]=pre[i+1];
        }

        int N=0;
        for(int i=0;i<n;i++){
            pre[i]+=N;
            if(customers[i]=='N') N++;
        }
        if(N==0) return n;

        int ans=0;
        for(int i=1;i<n;i++){
            if(pre[ans]>pre[i]) ans=i;
        }
        if(pre[ans]>N) ans=n;
        return ans;
    }
};