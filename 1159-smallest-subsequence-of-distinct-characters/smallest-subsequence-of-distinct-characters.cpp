class Solution {
public:
    void f(string& s,vector<int>& v,int i,string str,string& ans){
        if(i>=s.size()){
            for(auto it:v){
                if(it!=0) return ;
            }
            if(ans=="") ans=str;
            ans=min(ans,str);
            return;
        }
        //take
       
        if(v[s[i]-'a']!=0){
            v[s[i]-'a']=0;
            f(s,v,i+1,str+s[i],ans);
            v[s[i]-'a']=1;
        }
        
        f(s,v,i+1,str,ans);
    }
    string smallestSubsequence(string s) {
        vector<int> v(26,0);
        for(auto it:s){
            v[it-'a']++;
        }

        stack<char> st;
        vector<int> vis(26,0);

        for(int i=0;i<s.size();i++){
            while(!st.empty() && st.top()>s[i] && v[st.top()-'a']!=0 && vis[s[i]-'a']==0){
                vis[st.top()-'a']=0;
                st.pop();
            }
            if(vis[s[i]-'a']==0) st.push(s[i]);
            vis[s[i]-'a']=1;
            v[s[i]-'a']--;
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};