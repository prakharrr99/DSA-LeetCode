class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        vector<int> f1(26,0);
        vector<int> f2(26,0);

        for(auto it:s1) f1[it-'a']++;

        int i=0;
        int j=0;
        for(j=0;j<s1.size();j++){
            f2[s2[j]-'a']++;
        }
        if(f1==f2) return true;

        while(j<s2.size()){
            f2[s2[i++]-'a']--;
            f2[s2[j++]-'a']++;

            if(f1==f2) return true;
            
        }
        return false;
    }
};