class Solution {
public:
    int find(vector<int>& r,int hp,vector<int>& d,int i){
        int low=0;int high=i;
        int ans=-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            int damage=d[i]-((mid>0)?d[mid-1]:0);
            if(hp-damage>=r[i]){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    long long totalScore(int hp, vector<int>& d, vector<int>& r) {
        int n=d.size();
        for(int i=1;i<n;i++){
            d[i]=d[i]+d[i-1];
        }
        
        long long ans=0;
        for(int i=1;i<n;i++){
            int j=find(r,hp,d,i);
            if(j==-1) j=i+1;
            ans+=(i-j+1);
        }

        if(hp-d[0]>=r[0]) ans++;
        return ans;
    }
};