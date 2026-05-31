class Solution {
public:
    string reorganizeString(string s) {
        auto cmp=[](pair<char,int>& a,pair<char,int>& b){
            if(a.second!=b.second) return a.second<b.second;
            return a.first>b.first;
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)> pq(cmp);
        vector<int> f(26,0);
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(f[i]!=0){
                pq.push({i+'a',f[i]});
            }
        }
        string str;
        while(!pq.empty()){
            pair<char,int> a=pq.top();
            pq.pop();

            int x=0;
            for(int i=0;i<2*a.second-1;i++){
                if(x==1){
                    if(pq.empty()) return "";
                    pair<char,int> b=pq.top();
                    pq.pop();
                    b.second--;
                    str.push_back(b.first);
                    if(b.second!=0) pq.push(b);
                    x=0;
                }
                else{
                    str.push_back(a.first);
                    x=1;
                }
            }
        }
        return str;

    }
};