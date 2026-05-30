class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        auto cmp=[](pair<int,int>& a,pair<int,int>& b){
            if(a.first!=b.first) return a.first>b.first;
            else return a.second>b.second;
        };
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

        for(int i=0;i<mat.size();i++){
            int o=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) o++;
            }
            pair<int,int> p;
            p={o,i};
            pq.push(p);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};