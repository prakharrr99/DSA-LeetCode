class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(int i=0;i<words.size();i++)
        {
            int a=0;
            for(int j=0;j<words[i].size();j++){
                a=(a+weights[words[i][j]-'a'])%26;
            }
            char c='z'-a;
            ans.push_back(c);
        }
        return ans;
    }
};