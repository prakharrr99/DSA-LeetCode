class Solution {
public:
    int minFlips(string s) {
        string s1;
        string s2;
        int a=0;
        for(int i=0; i<s.size();i++){
            if(a==0){
                s1.push_back('1');
                s2.push_back('0');
                a=1;
            }
            else{
                s2.push_back('1');
                s1.push_back('0');
                a=0;
            }
        }
        //JITNA S1 SE MATCH KAREGA UTNA HI S2 SE MATCH NI KAREGA VICE VERSA

        int b=0; int i=0; int j=0;
        for(j=0;j<s1.size();j++){
            if(s1[j]!=s[j]) b++;
        }
        int k=s1.size();
        int ans=min(b,k-b);
        string p=s1;

        if(k%2!=0){ // main part where it went wrong for some time
            s1.push_back('0');
        }
        s1=s1+p;
        s=s+s;
        while(j<s.size()){
            if(s1[i]!=s[i]) b--;
            if(s1[j]!=s[j]) b++;
            ans=min(ans,min(b,k-b));
            i++;
            j++;
        }
        return ans;
    }
};