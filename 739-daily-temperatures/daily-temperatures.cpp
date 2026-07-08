class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();

        vector<int> ans(n,0);
        stack<int> s;
        s.push(0);
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(s.top()!=0 && temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            if(s.top()!=0) ans[i]=s.top()-i;
            else ans[i]=0;
            s.push(i);
        }
        return ans;
    }
};