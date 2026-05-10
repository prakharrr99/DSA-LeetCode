class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());

        int h=0;
        for(int i=0;i<citations.size();i++){
            for(int j=0;j<citations.size();j++){
                if(i+1<=citations[j]){
                    if(i+1<=citations.size()-j){
                        h=max(h,i+1);
                        break;
                    }
                }
            }
        }
        return h;
    }
};