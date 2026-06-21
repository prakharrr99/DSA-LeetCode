class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;

        int n=strs.size();
        vector<string> temp;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(v[i]==1) continue;
            string s=strs[i];
            temp.push_back(s);
            sort(s.begin(),s.end());
            v[i]=1;
            for(int j=i+1;j<n;j++){
                if(v[j]==1 || s.size()!=strs[j].size()) continue;
                string s1=strs[j];
                sort(s1.begin(),s1.end());
                if(s1==s){
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