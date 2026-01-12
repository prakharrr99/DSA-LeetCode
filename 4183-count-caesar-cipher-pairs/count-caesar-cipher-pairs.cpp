class Solution {
private:
    string op(string s){
        int shift=s[0]-'a'; // how much to shift to make first as'a' that amount of shift we will do for all
        for(int i=0;i<s.size();i++){
            s[i]=(s[i]-'a'-shift+26)%26+'a';
        }
        return s;
    }
public:
    long long countPairs(vector<string>& words) {
        long long ans=0;
        for(int i=0;i<words.size();i++){
            words[i]=op(words[i]);
        }
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        for(auto it:m){
            ans+=1LL*it.second*(it.second-1)/2;
        }
        return ans;
    }
};