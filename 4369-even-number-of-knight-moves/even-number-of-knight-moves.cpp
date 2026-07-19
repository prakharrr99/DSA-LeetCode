class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int d=abs(target[0]-start[0])+abs(target[1]-start[1]);
        if(d&1) return false;
        return true;
    }
};