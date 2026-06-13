class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        unordered_map<int,char> m;
        for(int i=0;i<26;i++){
            char c='z'-i;
            m[i]=c;
            // cout<<m[]
        }
        for(int i=0;i<words.size();i++)
        {
            int a=0;
            for(int j=0;j<words[i].size();j++){
                a=(a+weights[words[i][j]-'a'])%26;
            }
            ans.push_back(m[a]);
        }
        return ans;
    }
};