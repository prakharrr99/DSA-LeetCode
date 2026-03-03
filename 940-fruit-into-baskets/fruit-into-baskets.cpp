class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0; int j=0;
        int a=INT_MIN;
        unordered_map<int,int> m;
        int c=0;
        while(j<fruits.size()){
            if(m[fruits[j]]==0) c++;
            m[fruits[j]]++;
            while(c>2){
                if(m[fruits[i]]==1) c--;
                m[fruits[i]]--;
                i++;
            }
            if(c<=2) a=max(a,j-i+1);
            j++;
        }
        return a;
    }

};