class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {};
        vector<int> v(26,0);
        for(int i=0;i<p.size();i++){
            v[p[i]-'a']++;
        }

        int i=0; int j=0;
        vector<int> ans;
        vector<int> f(26,0);
        for(j=0;j<p.size();j++){
            if(v[s[j]-'a']>0) f[s[j]-'a']++;
        }
        while(j<s.size()){
            if(f==v) ans.push_back(i);
            if(v[s[i]-'a']>0) f[s[i]-'a']--;
            if(v[s[j]-'a']>0) f[s[j]-'a']++;
            i++;
            j++;
        }
        if(f==v) ans.push_back(i);
        return ans;
    }
};