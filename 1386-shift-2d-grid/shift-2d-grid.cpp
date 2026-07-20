class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for(auto it:grid){
            for(auto iit:it){
                temp.push_back(iit);
            }
        }
        vector<int> temp2(temp.size(),0);

        for(int i=0;i<temp.size();i++){
            temp2[(i+k)%temp.size()]=temp[i];
        }

        vector<vector<int>> g(grid.size(),vector<int>(grid[0].size(),0));

        int i=0;
        for(auto& it:g){
            for(auto& iit:it){
                iit=temp2[i++];
            }
        }

        return g;
    }
};