class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // sort(arr1.begin(),arr1.end());
        // sort(arr2.begin(),arr2.end());

        // int ans=0;
        // for(int i=0;i<arr1.size();i++){
        //     string s1=to_string(arr1[i]);
        //     for(int j=0;j<arr2.size();j++){
        //         string s2=to_string(arr2[j]);
                
        //         if(s1[0]!=s2[0]) continue;
                
        //         int p=0; int q=0;
        //         int c=0;
        //         while(p<s1.size() && q<s2.size()){
        //             if(s1[p]==s2[q]){
        //                 c++;
        //                 p++; q++;
        //             }
        //             else break;
        //         }
        //         ans=max(ans,c);
        //     }
        // }
        // return ans;

        unordered_set<string> sett;
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            string temp;
            for(int j=0;j<s.size();j++){
                temp.push_back(s[j]);
                sett.insert(temp);
            }
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            string temp;

            for(int j=0;j<s.size();j++){
                temp.push_back(s[j]);
                if(sett.find(temp)!=sett.end()){
                    int b=temp.size();
                    ans=max(ans,b);
                }
                else break;
            }
        }
        return ans;
    }
};