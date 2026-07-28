class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        unordered_map<int,int> c;
        vector<int> v1;
        vector<int> v2;
        for(auto it:series1){
            m1[it[0]]=it[1];
            v1.push_back(it[0]);
        }
        for(auto it:series2){
            m2[it[0]]=it[1];
            v2.push_back(it[0]);
        }
        for(int i=0;i<series1.size();i++){
            int t=series1[i][0];
            int v=series1[i][1];

            c[t]=1;
            if(m2.find(t)!=m2.end()){
                ans.push_back({t,v+m2[t]});
            }
            else{
                auto x=lower_bound(v2.begin(),v2.end(),t);
                if(x==v2.end()){
                    ans.push_back({t,v});
                }
                else ans.push_back({t,v+m2[*x]});
            }
        }
        for(int i=0;i<series2.size();i++){
            int t=series2[i][0];
            int v=series2[i][1];

            if(c[t]) continue;
            if(m1.find(t)!=m1.end()){
                ans.push_back({t,v+m1[t]});
            }
            else{
                auto x=lower_bound(v1.begin(),v1.end(),t);
                if(x==v1.end()){
                    ans.push_back({t,v});
                }
                else ans.push_back({t,v+m1[*x]});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};