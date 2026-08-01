class Solution {
public:
    bool ispossible(long long mid,vector<int>& mon,vector<long long>& diff){
        for(int idx=0;idx<mon.size();idx++){
            
            if(mid+diff[idx]<mon[idx]) return false;
            mid=mid-mon[idx];
            if(mid<0) mid=0;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        
        vector<long long> diff(monsters.size()+1,0);

        for(int i=0;i<boosts.size();i++){
            int l=boosts[i][0];
            int r=boosts[i][1];

            diff[l]+=boosts[i][2];
            if(r+1<diff.size()) diff[r+1]-=boosts[i][2];
        }

        for(int i=1;i<diff.size();i++){
            diff[i]+=diff[i-1];
        }
        
        long long low=0;
        long long high=0;
        for(auto it:monsters){
            high+=it;
        }

        long long ans=high;
        while(high>=low){
            long long mid=low+(high-low)/2;
            if(ispossible(mid,monsters,diff)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    
};