class Solution {
public:
    int exp(int a,int b,int M){
        int ans=1;
        while(b){
            if(b&1){
                ans=(1LL*(ans%M)*(a%M))%M;
            }
            b=b>>1;
            a=(1LL*a*a)%M;
        }
        return ans%M;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int M=1e9+7;
        vector<pair<int,int>> p(s.size()+1,{0,0});
        vector<int> sum(s.size()+1,0);
        int d=0;
        int l=0;
        int su=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                d=(1LL*d*10)%M+(s[i]-'0');
                l++;
                su+=(s[i]-'0');
            }
            p[i+1].first=d;
            p[i+1].second=l;

            sum[i+1]=su;
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];

            int val=((p[r+1].first)%M-(1LL*p[l].first*exp(10,p[r+1].second-p[l].second,M))%M+M)%M;
            val=(1LL*val*(sum[r+1]-sum[l]))%M;

            ans.push_back(val);
        }
        return ans;

    }
};