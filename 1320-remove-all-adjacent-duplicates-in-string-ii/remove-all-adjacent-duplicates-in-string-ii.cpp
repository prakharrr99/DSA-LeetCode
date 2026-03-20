class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
       
        for(int i=0;i<s.size();i++){
            if(st.size()!=0 && st.top().first==s[i]){
                if(st.top().second==k-1){     
                    while(st.size()!=0 && st.top().first==s[i]){
                        st.pop();
                    }
                }
                else st.push({s[i],st.top().second+1});
            }
            else{  
                st.push({s[i],1});
            }
        }
        string ans;
        while(st.size()!=0){
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};