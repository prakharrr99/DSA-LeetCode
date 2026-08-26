class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len=INT_MAX;
        int i=0;
        int j=0;
        vector<int> f(2,0);
        vector<string> v;
        while(j<s.size()){
            f[s[j]-'0']++;
            while(f[1]>=k){
                len=min(len,j-i+1);
                v.push_back(s.substr(i,j-i+1));
                f[s[i]-'0']--;
                i++;
            }
            j++;
        }
        if(len==INT_MAX) return ""; 
        cout<<len<<endl;
        // s.substr(i,j-i+1) ---> start from ith index and take (j-i+1) no. of elements
        vector<string> ans;
        for(auto it:v){
            if(it.size()==len){
                ans.push_back(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};