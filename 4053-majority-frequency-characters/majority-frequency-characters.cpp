class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> f(26,0);
        for(int i=0;i<s.size();i++){
            f[s[i]-'a']++;
        }
        unordered_map<int,string> m;
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

        string p;
        int freq=0;
        for(auto it:m){
            if(it.second.size()==maxi){
                freq=max(freq,it.first);
            }
        }
        for(auto it:m){
            if(it.second.size()==maxi && freq==it.first) return it.second;
        }

        return "";
    }
};