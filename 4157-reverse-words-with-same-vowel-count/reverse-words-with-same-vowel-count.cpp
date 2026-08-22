class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> v;
        string str;
        for(auto it:s){
            if(it==' '){
                v.push_back(str);
                str.clear();
            }
            else str.push_back(it);
        }
        int c=0;
        if(str.size()!=0) v.push_back(str);
        for(auto iit:v[0]){
            if(iit=='a' || iit=='e' || iit=='i' || iit=='o' || iit=='u'){
                c++;
            }
        }
        for(int i=1;i<v.size();i++){
            string t=v[i];
            int count=0;
            for(auto iit:t){
                if(iit=='a' || iit=='e' || iit=='i' || iit=='o' || iit=='u'){
                    count++;
                }
            }
            if(count==c){
                reverse(v[i].begin(),v[i].end());
            }
        }
        string ans;
        for(auto it:v){
            ans+=it;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};