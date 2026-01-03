class Solution {
private:
    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int ans=INT_MIN;
        int i=0; int j=0;
        int vowel=0;
        while(j<s.size()){
            while(j-i+1>k){
                ans=max(ans,vowel);
                if(isvowel(s[i])) vowel--;
                i++;
            }
            if(isvowel(s[j])) vowel++;
            j++;
        }
        ans=max(ans,vowel);
        if(ans==INT_MIN) return 0;
        return ans;
    }
};