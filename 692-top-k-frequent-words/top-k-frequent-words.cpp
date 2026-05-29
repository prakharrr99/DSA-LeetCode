class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {

        auto cmp=[](pair<string,int>& a,pair<string,int>& b){
            if(a.second!=b.second) return a.second<b.second;
            else return a.first>b.first;
        };

        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(cmp)> pq(cmp);

        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++) m[words[i]]++;

        for(auto it:m) pq.push({it.first,it.second});

        vector<string> s;
        for(int i=0;i<k;i++){
            string str=pq.top().first;
            s.push_back(str);
            pq.pop();
        }
        return s;
    }
};