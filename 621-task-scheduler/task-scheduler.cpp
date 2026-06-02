class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26,0);
        for(int i=0;i<tasks.size();i++){
            f[tasks[i]-'A']++;
        }
       

        priority_queue<int> pq;

        for(int i=0;i<26;i++){
            if(f[i]!=0) pq.push(f[i]);
        }

        int time=0;
        while(!pq.empty()){
            int b=n+1;
            vector<int> temp;
            
            while(b && !pq.empty()){ 
                temp.push_back(pq.top());
                temp[temp.size()-1]--;
                
                pq.pop();
                time++;
                b--;
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]!=0) pq.push(temp[i]);
            }
            if(pq.empty()) break;
            time+=b;
        }
        return time;
    }
};