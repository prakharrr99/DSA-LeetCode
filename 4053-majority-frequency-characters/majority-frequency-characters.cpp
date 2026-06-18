class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> f(26,0);
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']++;
        }
        map<int,vector<char>> m;
        for(int i=0;i<26;i++){
            if(f[i]!=0){
                m[f[i]].push_back(i+'a');
            }
        }

    
        int maxi=0;
        for(auto it:m){
            int n=it.second.size();
            maxi=max(maxi,n);
        }

        vector<char> ans;
        for(auto it:m){
            if(it.second.size()==maxi){
                ans=it.second;
            }
        }

        string p;
        for(auto it:ans){
            p.push_back(it);
        }
        return p;
    }
};