class Solution {
private:
    long long sum(vector<int>& piles,int a){
        long long s=0;
        for(int i=0;i<piles.size();i++){
            s+=(piles[i]+a-1)/a;
        }
        return s;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int a=0;
        for(int i=1;i<piles.size();i++){
            if(piles[a]<piles[i]) a=i;
        }
        int j=piles[a];
        int i=1;
        int mid=i+(j-i)/2; int ans=j;
        while(j>=i){
            long long s=sum(piles,mid);
            if(s<=h){
                ans=mid;
                j=mid-1;
            }
            else if(s>h){
                i=mid+1;
            }
            mid=i+(j-i)/2;
        }
        return ans;
    }
};