class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        unordered_map<string,int> m;
        int i=0;
        while(i<s.size()){
            string str;
            str.push_back(s[i]);
            while(i<s.size() && m.find(str)!=m.end()){
                i++;
                if(i<s.size()) str.push_back(s[i]);
            }
            if(m[str]==0){
                ans.push_back(str);
                m[str]++;
            } 
            i++;
        }
        return ans;
    }
};