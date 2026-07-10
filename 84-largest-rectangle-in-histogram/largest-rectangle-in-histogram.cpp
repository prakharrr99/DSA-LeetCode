class Solution {
public:
    vector<int> small(vector<int>& heights){
        stack<int> s;
        vector<int> ans;
        s.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            ans.push_back(s.top());
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> greater(vector<int>& heights){
        stack<int> s;
        vector<int> ans;
        s.push(-1);
        for(int i=0;i<heights.size();i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            ans.push_back(s.top());
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev=greater(heights);
        vector<int> next=small(heights);

        int area=0;
        for(auto& it:next){
            if(it==-1) it=heights.size();
        }
        for(int i=0;i<heights.size();i++){
            int newarea=heights[i]*abs(next[i]-prev[i]-1);
            area=max(area,newarea);
        }
        return area;
    }
};