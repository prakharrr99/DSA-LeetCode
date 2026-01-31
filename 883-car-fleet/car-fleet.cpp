class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> pq;
        for(int i=0;i<position.size();i++){
            pq.push_back({position[i],(target-position[i])/(1.0*speed[i])});
        }
        sort(pq.rbegin(),pq.rend()); // reverse order
        int fleet=0;
        stack<pair<int,double>> s;
        for(int i=0;i<pq.size();i++){
            if(s.size()==0){
                s.push(pq[i]);
                fleet++;
            }
            else{
                if(pq[i].second<=s.top().second && pq[i].first<s.top().first){
                    //same fleet
                }
                else{
                    fleet++;
                    s.pop();
                    s.push(pq[i]);
                }
            }
        }
        return fleet;
    }
};