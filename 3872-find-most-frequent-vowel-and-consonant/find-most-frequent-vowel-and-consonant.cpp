class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> m;
        for(auto it:s){
            m[it]++;
        }
        int ma=0; int maa=0;
        for(auto it:m){
            if(it.first=='a' || it.first=='e' || it.first=='i' || it.first=='o' || it.first=='u') ma=max(ma,it.second);
            else maa=max(maa,it.second);
        }
        return ma+maa;
    }
};