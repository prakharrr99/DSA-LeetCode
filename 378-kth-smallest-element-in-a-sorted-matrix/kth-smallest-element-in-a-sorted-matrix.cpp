class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int b=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(b<k){
                    pq.push(matrix[i][j]);
                    b++;
                }
                else{
                    if(matrix[i][j]<pq.top()){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        int a=pq.top();
        return a;
    }
};