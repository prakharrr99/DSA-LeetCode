class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int a=0; int b=0;
        int p=1; 
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1) p++;
            else{
                a=max(a,p);
                p=1;
            }
        }
        a=max(a,p);
        p=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1) p++;
            else{
                b=max(b,p);
                p=1;
            }
        }
        b=max(b,p);
        int area=min(a,b);
        return (area+1)*(area+1);
    }
};