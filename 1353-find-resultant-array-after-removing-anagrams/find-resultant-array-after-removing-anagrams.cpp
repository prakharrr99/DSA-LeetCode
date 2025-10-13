class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for(int i=0;i<words.size();i++){
            string s=words[i];
            sort(s.begin(),s.end());
            if(i!=0){
                string str=words[i-1];
                sort(str.begin(),str.end());
                if(str!=s) ans.push_back(words[i]);
            }
            else{
                ans.push_back(words[i]);
            }
            // for(int j=i-1;j<ans.size();j++){
            //     str=ans[j];
            //     sort(str.begin(),str.end());
            //     if(s==str) break;
            // }
            //if(ans.size()==0 || str!=s) ans.push_back(words[i]);
        }
        return ans;
    }
};