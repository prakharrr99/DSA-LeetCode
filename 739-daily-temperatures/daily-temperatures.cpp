class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> s;
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            while(s.size()!=0 && temperatures[s.top()]<temperatures[i]){
                a[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return a;
    }
};