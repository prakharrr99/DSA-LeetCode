class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<pair<double,int>> store;
        for(int i=0;i<points.size();i++){
            double val=sqrt(1.0*points[i][0]*points[i][0]+1.0*points[i][1]*points[i][1]);
            store.push_back({val,i});
        }
        sort(store.begin(),store.end());
        for(int i=0;i<k;i++){
            ans.push_back({points[store[i].second][0],points[store[i].second][1]});
        }
        return ans;
    }
};