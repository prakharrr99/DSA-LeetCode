class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int a=0;
        // vector<int> v(words.size(),0);
        for(int i=0;i<words.size();i++){
            if(words[i].size()<k) continue;
            while(words[i].size()!=k) words[i].pop_back();
        }
        sort(words.begin(),words.end());
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            if(words[i].size()<k) continue;
            // if(m.find(words[i])!=m.end()) a++;
            m[words[i]]++;
        }
        for(auto it:m){
            if(it.second>1) a++;
        }
        
        // for(int i=0;i<words.size();i++){
        //     if(words[i].size()<k) continue;
        //     if(v[i]==1) continue;
        //     int f=0;
        //     for(int j=i+1;j<words.size();j++){
        //         if(f!=0) break;
        //         if(words[j].size()<k) continue;
        //         int b=0;
        //         string str;
        //         while(b<k && words[i][b]==words[j][b]){
        //             str.push_back(words[i][b]);
        //             b++;
        //         }
        //         if(b!=k) continue;
        //         if(m.find(str)!=m.end()) continue;
        //         if(b==k){
        //             v[j]=1;
        //             f++;
        //             a++;
        //             m[str]++;
        //         }
        //     }
        // }
        return a;
    }
};