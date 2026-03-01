class Solution {
public:
    int minPartitions(string n) {
        char k;
        for(int i=0;i<n.size();i++){
            if(n[i]>k) k=n[i];
        }
        return k-'0';
    }
};