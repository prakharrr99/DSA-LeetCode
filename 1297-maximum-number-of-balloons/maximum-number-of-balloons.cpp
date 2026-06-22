class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(auto it: text){
            m[it]++;
        }
        string s="balloon";

        int instant=0;
        while(1){
            int a=0;
            for(auto it:s){
                if(m.find(it)!=m.end()){
                    m[it]--;
                    if(m[it]==0) m.erase(it);
                }
                else{
                    a=1;
                    break;
                }
            }
            if(a==1) break;
            instant++;
        }
        return instant;  
    }
};