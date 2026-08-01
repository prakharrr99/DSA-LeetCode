class Solution {
public:
    bool dfs(vector<vector<int>>& g,vector<int>& v,vector<int>& p,vector<int>& check,int node){
        v[node]=1;
        p[node]=1;
        check[node]=0;

        for(auto it:g[node]){
            if(v[it]!=1){
                if(dfs(g,v,p,check,it)){
                    check[node]=0;
                    return true;
                }
            }
            else if(v[it] && p[it]){
                check[node]=0;
                return true;
            }
        }
        p[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        vector<int> p(g.size(),0);
        vector<int> safe;
        vector<int> v(g.size(),0);
        vector<int> check(g.size(),0);

        for(int i=0;i<g.size();i++){
            if(!v[i]){
                dfs(g,v,p,check,i);
            }
        }
        for(int i=0;i<g.size();i++){
            if(check[i]==1) safe.push_back(i);
        }
        return safe;
    }
};