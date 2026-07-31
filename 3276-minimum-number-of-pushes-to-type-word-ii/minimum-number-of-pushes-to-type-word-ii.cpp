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
        vector<int> v(26,0);
        while(!pq.empty()){
            pair<char,int>p=pq.top();
            pq.pop();
            char it=p.first;
            if(f<=9){
                v[it-'a']=1;
                c+=(v[it-'a']*p.second);
                f++;
            }
            else if(f<=17){
                v[it-'a']=2;
                c+=(v[it-'a']*p.second);
                f++;
            }
            else if(f<=25){
                v[it-'a']=3;
                c+=(v[it-'a']*p.second);
                f++;
            }
            else if(f<=27){
                v[it-'a']=4;
                c+=(v[it-'a']*p.second);
                f++;
            }
        }
        return c;
    }
};