class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";

        vector<int> mt(256,0);
        for(auto it:t) mt[it]++;
         
        vector<int> ms(256,0);
        
        int i=0;int j=0;
        int start=-1;
        int len=INT_MAX;
        while(j<s.size()){
            if(mt[s[j]]!=0){
                ms[s[j]]++;
            }
            int c=0;
            for(int k=0;k<256;k++){
                if(ms[k]>=mt[k]) continue;
                else{
                    c=1;
                    break;
                }
            }
            if(c==0){
                if(len> j-i+1){
                    len=j-i+1;
                    start=i;
                }
                while(i<s.size() && (mt[s[i]]==0 || (mt[s[i]]!=0 && ms[s[i]]>mt[s[i]]) )){
                    if(mt[s[i]]!=0) ms[s[i]]--;
                    i++;
                    if(len>j-i+1){
                        len=j-i+1;
                        start=i;
                    }
                }
            }
            j++;
        }

        string s1;

        if(start==-1) return s1;

        for(int k=start;k<start+len && k<s.size();k++){
            s1.push_back(s[k]);
        }
        return s1;
    }
};