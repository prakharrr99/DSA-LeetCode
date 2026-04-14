class Solution {
public:

    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        double a=sides[0];
        double b=sides[1];
        double c=sides[2];
        vector<double> ans;
        if(a>=b+c) return ans;
        else if(b>=a+c) return ans;
        else if(c>=a+b) return ans;

        double a1=acos((b*b+c*c-a*a)/(2*b*c));
        double a2=acos((b*b+a*a-c*c)/(2*b*a));
        double a3=acos((c*c+a*a-b*b)/(2*c*a));

        a1=a1*180/M_PI;
        a2=a2*180/M_PI;
        a3=a3*180/M_PI;

        
        ans.push_back(a1);
        ans.push_back(a2);
        ans.push_back(a3);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};