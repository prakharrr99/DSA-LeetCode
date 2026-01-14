class Solution {
private:
    void help(vector<vector<int>>& ans,vector<int>& a,vector<int>& b,int k,int id){
        if(a.size()==k){
            ans.push_back(a);
            return ;
        }
        if(id>=b.size()) return;
        a.push_back(b[id]);
        help(ans,a,b,k,id+1);
        a.pop_back();
        help(ans,a,b,k,id+1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        vector<vector<int>> ans;
        vector<int> b;
        for(int i=1;i<=n;i++) b.push_back(i);
        int id=0;
        help(ans,a,b,k,id);
        return ans;
    }
};