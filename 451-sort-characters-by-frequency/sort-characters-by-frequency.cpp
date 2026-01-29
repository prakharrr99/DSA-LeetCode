class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<256;i++){
            if(freq[i]!=0) pq.push({freq[i],i});
        }
        string ans;
        while(!pq.empty()){
            int i=0;
            while(i<pq.top().first){
                char c=pq.top().second;
                ans.push_back(c);
                i++;
            }
            pq.pop();
        }
        return ans;
    }
};