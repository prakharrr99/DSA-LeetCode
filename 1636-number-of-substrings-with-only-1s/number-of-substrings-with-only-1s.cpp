class Solution {
public:
    int numSub(string s) {
        int i=0;
        const long long MOD = 1e9 + 7;
        for(int k=0;k<s.size();k++)
            if(s[k]=='1'){ i=k; break;}
        int j=i;
        long long int ans=0;
        while(j<s.size()){
            if(s[j]=='1'){
                j++;
            }
            else{
                ans+=1LL*(j-i)*(j-i+1)/2%MOD;
                j++;
                i=j;
            }
        }
        ans+=1LL*(j-i)*(j-i+1)/2%MOD;
        return ans;
    }
};