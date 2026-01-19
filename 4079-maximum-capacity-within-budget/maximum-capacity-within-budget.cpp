class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>>v;
        for(int i=0;i<costs.size();i++){
            v.push_back({costs[i],capacity[i]});
        }
        sort(v.begin(),v.end());

        int ans=0;
        vector<int> largest(v.size(),0);
        largest[0]=v[0].second;
        for(int i=1;i<v.size();i++){
            largest[i] = max(largest[i-1], v[i].second);
        }

        for(int i=0;i<v.size();i++){
            int a=-1;
            if(v[i].first<budget){
                a=v[i].second;
            }
            else break;
            
            int need=budget-v[i].first-1;
            if(i==0 || need==0){
                ans=max(ans,a);
                continue;
            } 
            int low=0; int high=i-1; int b=-1;
            while(high>=low){
                int mid=low+(high-low)/2;
                if(v[mid].first<=need){
                    b=mid; low=mid+1;
                }
                else high=mid-1;
            }
            if(b==-1) ans=max(ans,a);
            else ans=max(a+largest[b],ans);
        }
        return ans;
    }
};