class Solution {
private:
    void next(vector<int> v,vector<int>& a){
        stack<int> s;
        s.push(-1);
        for(int i=v.size()-1;i>=0;i--){
            while(s.size()!=0 && s.top()!=-1 && v[s.top()]>=v[i]){
                s.pop();
            }
            a[i]=s.top();
            s.push(i);
        }
    }
    void prev(vector<int> v,vector<int>& a){
        stack<int> s;
        s.push(-1);
        for(int i=0;i<v.size();i++){
            while(s.size()!=0 && s.top()!=-1 && v[s.top()]>=v[i]){
                s.pop();
            }
            a[i]=s.top();
            s.push(i);
        }
    }
    int areaa(vector<int> v){
        vector<int> nexts(v.size(),0);
        next(v,nexts);
        vector<int> prevs(v.size(),0);
        prev(v,prevs);
        int area=INT_MIN;
        for(int i=0;i<v.size();i++){
            if(nexts[i]==-1) nexts[i]=v.size();
            int newarea=v[i]*(nexts[i]-prevs[i]-1);
            area=max(area,newarea);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> temp(matrix[0].size(),0);
        int ans=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    temp[j]=0;
                }
                else{
                    temp[j]+=1;
                }
            }
            ans=max(ans,areaa(temp));
        }
        return ans;
    }
};