class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";

        vector<int> f(256,0);
        for(int i=0;i<t.size();i++){
            f[t[i]]++;
        }

        int i=0; int j=0;
        int count=0;
        int ans=INT_MAX;
        int startidx=-1;
        while(j<s.size()){
            while(count==t.size()){
                if(ans>j-i){
                    ans=j-i;
                    startidx=i;
                }
                f[s[i]]++;
                if(f[s[i]]>0) count--;
                i++;
            }
            if(f[s[j]]>0){
                count++; 
            }
            f[s[j]]--;
            j++;
        }
        while(count==t.size()){
            if(ans>j-i){
                ans=j-i;
                startidx=i;
            }
            f[s[i]]++;
            if(f[s[i]]>0) count--;
            i++;
        }
        
        if(ans==INT_MAX) return "";
        return s.substr(startidx, ans);
    }
};