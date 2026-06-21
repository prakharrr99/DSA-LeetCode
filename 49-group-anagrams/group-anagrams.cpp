class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;

        int n=strs.size();
        vector<string> str=strs;
        for(int i=0;i<n;i++){
            sort(str[i].begin(),str[i].end());
        }
        vector<int> v(n,0);
        vector<string> temp;
        for(int i=0;i<n;i++){
            if(v[i]==1) continue;
            v[i]=1;
            temp.push_back(strs[i]);
            for(int j=i+1;j<n;j++){
                if(v[j]==1 || str[i].size()!=str[j].size()) continue;
                if(str[i]==str[j]){
                    temp.push_back(strs[j]);
                    v[j]=1;
                }
            }
            r.push_back(temp);
            temp.clear();
        }
        return r;
    }
};