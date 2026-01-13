class Solution {
private:
    void fun(double y,vector<int>& v,double& u,double& b){
        if(y>v[1]+v[2]) b+=1.0*v[2]*v[2];
        else if(y<v[1]) u+=1.0*v[2]*v[2];
        else{
            u+=1.0*(v[1]+v[2]-y)*v[2];
            b+=1.0*(y-v[1])*v[2];
        }
    }
    double mini(double a,double b){
        if(a>b) return b;
        return a;
    }
    double maxi(double a,double b){
        if(a>b) return a;
        return b;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double i=INT_MAX;
        double j=INT_MIN;
        for(int k=0;k<squares.size();k++){
            i=mini(i,squares[k][1]);
            j=maxi(j,squares[k][1]+squares[k][2]);
        }
        double mid=i+(j-i)/2;
        while(j-i>1e-6){
            double u=0;
            double b=0;
            for(int i=0;i<squares.size();i++){
                fun(mid,squares[i],u,b);
            }
            if(u>b) i=mid;
            else j=mid;
            mid=i+(j-i)/2;
        }
        return (i+j)/2;
    }
};