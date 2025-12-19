class Solution {

public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> f(26,0);
        for(int i=0;i<s1.size();i++){
            f[s1[i]-'a']++;
        }
        int i=0; int j=0;
        vector<int> f1(26,0);
        while(j<s1.size()){
            
            f1[s2[j]-'a']++;
            j++;
        }

        if(f==f1) return true;
        f1[s2[i]-'a']--;
        i++;
        while(j<s2.size()){
            f1[s2[j]-'a']++;
            if(f==f1) return true;
            f1[s2[i]-'a']--;
            i++;
            j++;
        }
        return false;
    }
};