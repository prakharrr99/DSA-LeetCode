class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> m;
        vector<bool> visited(arr.size(),false);
        queue<int> q;

        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }

        q.push(0);
        visited[0]=true;

        int steps=0;
        while(!q.empty()){

            int size=q.size();
            while(size--){
                int c=q.front();
                q.pop();

                if(c==arr.size()-1) return steps;
                int right=c+1;
                int left=c-1;

                if(right<arr.size() && !visited[right]){
                    visited[right]=1;
                    q.push(right);
                }
                if(left>=0 && !visited[left]){
                    visited[left]=1;
                    q.push(left);
                }

                for(auto it:m[arr[c]]){
                    if(!visited[it]) q.push(it);
                }
                m.erase(arr[c]);
            }
            
            steps++;
        }
        return -1;
    }
};

