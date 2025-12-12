class Solution {
private:
    bool isana(string s1,string s2){
        if(s1.size()!=s2.size()) return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<int> store(strs.size(),0);

        for(int i=0;i<strs.size();i++){
            if(store[i]==1) continue;
            vector<string> temp;
            for(int j=i+1;j<strs.size();j++){
                if(store[j]==1) continue;
                if(isana(strs[i],strs[j])){
                    store[j]=1;
                    temp.push_back(strs[j]);
                }

            }
            temp.push_back(strs[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};