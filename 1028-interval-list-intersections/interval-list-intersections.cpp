class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0; int j=0;
        while(i<firstList.size() && j<secondList.size()){
            int s1=firstList[i][0];
            int e1=firstList[i][1];
            int s2=secondList[j][0];
            int e2=secondList[j][1];
            if(s1>=s2){
                if(s1<=e2){
                    ans.push_back({max(s1,s2),min(e1,e2)});
                }
            }
            else{
                if(s2<=e1){
                    ans.push_back({max(s1,s2),min(e1,e2)});
                }
            }
            if(e1>=e2) j++;
            else i++;
        }
        return ans;
    }
};