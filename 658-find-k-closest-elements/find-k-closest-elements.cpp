class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        auto cmp=[](pair<int,int>& a,pair<int,int>& b){
            if(abs(a.first-a.second)!=abs(b.first-b.second)){
                return abs(a.first-a.second)>abs(b.first-b.second);
            }
            else return a>b;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],x});
        }

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};