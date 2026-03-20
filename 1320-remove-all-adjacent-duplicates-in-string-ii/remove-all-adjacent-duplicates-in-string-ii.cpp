class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
       
        for(int i=0;i<s.size();i++){
            if(st.size()!=0 && st.top().first==s[i]){
                if(st.top().second==k-1){     
                    st.pop();
                }
                else st.top().second++;
            }
            else st.push({s[i],1});
        }
        string ans;
        while(st.size()!=0){
            for(int i=0;i<st.top().second;i++){
                ans.push_back(st.top().first);
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};