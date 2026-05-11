class Solution {
public:
    bool valid(vector<int>& piles, int h,long long v){
        long long a=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%v!=0){
                a+=(piles[i]/v+1);
            }
            else a+=(piles[i]/v);
        }
        return a<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1;
        long long high=0;
        for(int i=0;i<piles.size();i++) high+=piles[i];

        int ans=-1;
        while(high>=low){
            long long mid=low+(high-low)/2;

            if(valid(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};