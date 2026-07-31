class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> fre(26,0);
        for(auto it:word){
            fre[it-'a']++;
        }
        
        auto cmp=[](pair<char,int>& a,pair<char,int>& b){
            return a.second<b.second;
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)> pq(cmp);
        for(int i=0;i<26;i++){
            pq.push({'a'+i,fre[i]});
        }

        int c=0;
        int f=2;
        
        while(!pq.empty()){
            pair<char,int>p=pq.top();
            pq.pop();
            char it=p.first;
            if(f<=9){
                c+=(1*p.second);
                f++;
            }
            else if(f<=17){
                c+=(2*p.second);
                f++;
            }
            else if(f<=25){
                c+=(3*p.second);
                f++;
            }
            else if(f<=27){
                c+=(4*p.second);
                f++;
            }
        }
        return c;
    }
};