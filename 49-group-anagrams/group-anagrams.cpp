class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;

        unordered_map<string,vector<string>> m;
        int n=strs.size();
        vector<string> v=strs;
        for(int i=0;i<n;i++){
            sort(v[i].begin(),v[i].end());
            m[v[i]].push_back(strs[i]);
        }
        for(auto it:m){
            r.push_back(it.second);
        }
        return r;
    }
};