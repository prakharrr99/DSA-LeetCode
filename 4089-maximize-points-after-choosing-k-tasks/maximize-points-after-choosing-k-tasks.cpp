class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n=t1.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            if(t1[i]>=t2[i]){
                t2[i]=t1[i];
                if(k>0) k--;
            }
            else{
                pq.push({t2[i]-t1[i],i});
            }
        }
        
        while(k>0 && !pq.empty()){
            k--;
            pair<int,int> p=pq.top();
            pq.pop();
            t2[p.second]=t1[p.second];
        }

        long long ans=0;
        for(auto it:t2) ans+=it;
        return ans;
    }
};