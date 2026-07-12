class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> b=arr;
        unordered_map<int,int> m;
        sort(arr.begin(),arr.end());

        int a=1;
        int prev=INT_MAX;
        for(int i=0;i<n;i++){
            if(prev==INT_MAX || prev==arr[i]){
                m[arr[i]]=a;
                prev=arr[i];
            }
            else{
                a++;
                m[arr[i]]=a;
                prev=arr[i];
            }
        }
        for(int i=0;i<n;i++){
            b[i]=m[b[i]];
        }
        return b;
    }
};