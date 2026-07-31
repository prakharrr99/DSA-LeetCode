class Solution {
public:
    bool dfs(vector<int>& ans,vector<vector<int>>& g,vector<int>& v,int node,unordered_map<int,int>& terminal){
        if(terminal.find(node)!=terminal.end()) return true;

        v[node]=2;
        for(auto it:g[node]){
            if(v[it]!=2){
                if(dfs(ans,g,v,it,terminal)==false){
                    return false;
                }
                else{
                    terminal[it]=1;
                }
            }
            else{
                return false;
            }
        }
        v[node]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        
        vector<int> ans;
        unordered_map<int,int> terminal;

        for(int i=0;i<g.size();i++){
            if(g[i].size()==0){
                ans.push_back(i);
                terminal[i]=1;
            }
        }

        for(int i=0;i<g.size();i++){
            if(g[i].size()==0){
                // ans.push_back(i);
                // terminal[i]=1;
                continue;
            }
            vector<int> v(g.size(),0);
            if(dfs(ans,g,v,i,terminal)) ans.push_back(i);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};