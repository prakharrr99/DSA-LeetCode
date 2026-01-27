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
    }
};