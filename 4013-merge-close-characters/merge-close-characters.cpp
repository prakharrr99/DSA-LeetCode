class Solution {
public:
    string mergeCharacters(string s, int k) {
        string a=s;
        while(1){
            bool m=false;
            for(int i=0; i<a.size();i++){
                int j=i+1;
                while(j<a.size() && j-i<=k){
                   if(a[i]==a[j]){
                       a.erase(j,1);
                       m=true;
                    //    break;
                   }
                    else j++;                
                }    
                if(m) break;
            }
            if(!m) break;
        }
        return a;
    }
};