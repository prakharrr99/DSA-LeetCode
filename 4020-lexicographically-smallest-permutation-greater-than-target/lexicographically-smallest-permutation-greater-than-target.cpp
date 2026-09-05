class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> f(26,0);

        for(auto it:s){
            f[it-'a']++;
        }
        string ans;
        int check=0;
        for(int i=0;i<target.size();i++){
            if(f[target[i]-'a']>0){
                ans.push_back(target[i]);
                f[target[i]-'a']--;
            }
            else{
                for(int j=0;j<26;j++){
                    if(target[i]<j+'a' && f[j]>0){
                        ans.push_back('a'+j);
                        f[j]--;
                        check=1;
                        break;
                    }
                }
                if(check==0){
                    while(ans.size()>0){
                        char c=ans[ans.size()-1];
                        f[c-'a']++;
                        ans.pop_back();

                        for(int i=0;i<26;i++){
                            if(f[i]>0 && i+'a'>c){
                                ans.push_back(i+'a');
                                f[i]--;
                                for(int j=0;j<26;j++){
                                    while(f[j]>0){
                                        ans.push_back(j+'a');
                                        f[j]--;
                                    }
                                }
                                return ans;
                            }
                        }
                    }
                    return "";
                }
                for(int j=0;j<26;j++){
                    while(f[j]>0){
                        ans.push_back(j+'a');
                        f[j]--;
                    }
                }
                return ans;
            }
        }

        if(ans==target){
            while(ans.size()>0){
                char c=ans[ans.size()-1];
                f[c-'a']++;
                ans.pop_back();

                for(int i=0;i<26;i++){
                    if(f[i]>0 && i+'a'>c){
                        ans.push_back(i+'a');
                        f[i]--;
                        for(int j=0;j<26;j++){
                            while(f[j]>0){
                                ans.push_back(j+'a');
                                f[j]--;
                            }
                        }
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};