class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp=[](pair<int,int>& a,pair<int,int>& b){
            float d=sqrt(1.0*a.first*a.first+1.0*a.second*a.second);
            float d2=sqrt(1.0*b.first*b.first+1.0*b.second*b.second);
            return d>d2;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        
        for(int i=0;i<points.size();i++){
            pair<int,int> a;
            a={points[i][0],points[i][1]};
            pq.push(a);
        }

        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            vector<int> t;
            t.push_back(pq.top().first);
            t.push_back(pq.top().second);
            pq.pop();
            ans.push_back(t);
        }
        return ans;
    }
};