class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        auto cmp=[](vector<int>& a,vector<int>& b){
            return a[1]>b[1];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);

        int day=0;
        int t=0;
        int n=apples.size();
        while(day<n || !pq.empty()){
           
            if(day<n && apples[day]>0){
               pq.push({apples[day],day+days[day]});
            }
            while(!pq.empty() && (pq.top()[1]<=day || pq.top()[0]==0)) pq.pop();

            if(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                it[0]--;
                t++;
                pq.push(it);
            }
            day++;
        }
        return t;
    }
};