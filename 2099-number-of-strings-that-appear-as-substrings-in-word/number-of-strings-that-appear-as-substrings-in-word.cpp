class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto it:patterns){
            for(int i=0;i<word.size();i++){
                string s;
                int a=0;
                for(int j=i;j<word.size();j++){
                    s.push_back(word[j]);
                    if(s==it){
                        ans++;
                        a=1;
                        break;
                    }
                }
                if(a==1) break;
            }
        }
        return ans;
    }
};