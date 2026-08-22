class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
       
        int id=0;
        int curr=0;
        for(int i=0;i<gas.size();i++){
            curr+=gas[i];
            curr-=cost[i];
            if(curr<0){
                id=i+1;
                curr=0;
            }
        }
        return id;
    }
};