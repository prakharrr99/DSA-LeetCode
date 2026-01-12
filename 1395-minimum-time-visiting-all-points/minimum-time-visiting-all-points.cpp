class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int t=0;
        int a=points[0][0];
        int b=points[0][1];
        for(int i=1;i<points.size();i++){
            while(points[i][0]!=a || points[i][1]!=b){
                if(points[i][0]>a && points[i][1]>b){
                    t++; a++; b++;
                }
                else if(points[i][0]<a && points[i][1]<b){
                    t++; a--; b--;
                }
                else if(points[i][0]<a && points[i][1]>b){
                    t++; a--; b++;
                }
                else if(points[i][0]>a && points[i][1]<b){
                    t++; a++; b--;
                }
                else if(points[i][0]>a && points[i][1]==b){
                    t++; a++;
                }
                else if(points[i][0]<a && points[i][1]==b){
                    t++; a--;
                }
                else if(points[i][0]==a && points[i][1]>b){
                    t++; b++;
                }
                else if(points[i][0]==a && points[i][1]<b){
                    t++; b--;
                }
            }
        }
        return t;
    }
};