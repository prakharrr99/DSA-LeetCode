class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int m=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            m=min(m,abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>> a;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])==m) a.push_back({arr[i-1],arr[i]});
        }
        sort(a.begin(),a.end());
        return a;
    }
};