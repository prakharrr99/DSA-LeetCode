class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        for(int i=0;i<A.size();i++){
            m[A[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<B.size();i++){
            int j=0; int c=0;
            while(j<=i){
                if(m.find(B[j])!=m.end() && m[B[j]]<=i) c++;
                j++;
            }
            ans.push_back(c);
        }
        return ans;

        // int n=A.size();
        // vector<int>res(n+1,0);
        // vector<int>ress;
        // int a=0;
        // for(int i=0;i<n;i++) {
        //     if(++res[A[i]]==2)
        //     a++;
        //     if(++res[B[i]]==2)
        //     a++;
        //     ress.push_back(a);
        // }
        // return ress;
    }
};