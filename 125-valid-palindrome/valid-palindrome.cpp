#include <bits/stdc++.h> 
char tolower(char ch){
    if(ch>='a'&& ch<='z') return ch;
    return ch-'A'+'a';
}
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                str.push_back(tolower(s[i]));// size chota pad raha h isliye overflow thats why we are using push_back operation
            }
        }
        
        string str2=str;
        reverse(str2.begin(),str2.end());
        return str2==str;

    }
};