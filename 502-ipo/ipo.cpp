class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<int> visited(profits.size(),0);

        vector<vector<int>> a;
        for(int i=0;i<profits.size();i++){
            a.push_back({capital[i],profits[i]});
        }
        sort(a.begin(),a.end());

        auto cmp=[](vector<int>& a ,vector<int>& b){
            return a[1]<b[1];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq;

        int i=0;

        while(k){
            while(i<a.size() && w>=a[i][0]){
                pq.push(a[i]);
                i++;
            }
            if(pq.empty()) return w;
            vector<int> b=pq.top();
            w+=b[1];
            pq.pop();
            k--;
        }
        return w;
    }
};