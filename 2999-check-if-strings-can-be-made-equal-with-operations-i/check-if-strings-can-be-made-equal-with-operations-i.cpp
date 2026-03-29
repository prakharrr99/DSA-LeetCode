class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // unordered_map<char,int> m;
        // vector<int> m(26,0);
        unordered_map<char,vector<int>> m;
        for(int i=0;i<s1.size();i++){
            m[s1[i]].push_back(i);
        }

        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) continue;

            if(m.find(s2[i])!=m.end()){
                for(int j=0;j<m[s2[i]].size();j++){
                    if(abs(m[s2[i]][j]-i)==2){
                        swap(s1[m[s2[i]][j]],s1[i]);
                    }
                }
            }
        }
        return s1==s2;
    }
};