class Solution {
public:
    bool solve(vector<int>& arr, int i,vector<int>& visited){
        if(i<0 || i>=arr.size() || visited[i]==1) return false;
        if(arr[i]==0) return true;

        visited[i]=1;
        if(solve(arr,i+arr[i],visited)) return true;
        if(solve(arr,i-arr[i],visited)) return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(),0);
        return solve(arr,start,visited);
    }
};