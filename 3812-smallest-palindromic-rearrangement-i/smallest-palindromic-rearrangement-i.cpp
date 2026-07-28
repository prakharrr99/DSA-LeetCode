class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> f1(26,0);
        for(auto it:s){
            f1[it-'a']++;
        }

        string ans;
        for(int i=0;i<26;i++){
            if(f1[i]){
                char c=i+'a';
                if(f1[i]&1){
                    for(int j=0;j<(f1[i]-1)/2;j++){
                        ans.push_back(c);
                    }
                }
                else{
                    for(int j=0;j<f1[i]/2;j++){
                        ans.push_back(c);
                    }
                }
            }
        }
        for(int i=0;i<26;i++){
            if(f1[i]&1){
                ans.push_back(i+'a');
            }
        }
        for(int i=25;i>=0;i--){
            if(f1[i]){
                char c=i+'a';
                if(f1[i]&1){
                    for(int j=0;j<(f1[i]-1)/2;j++){
                        ans.push_back(c);
                    }
                }
                else{
                    for(int j=0;j<f1[i]/2;j++){
                        ans.push_back(c);
                    }
                }
            }
        }
        return  ans;
    }
};