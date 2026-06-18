class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12) hour=0;
        double d1=30*hour;
        double d2=0;
        
        d1+=0.5*minutes;
        d2+=6*minutes;
    
        double ans=abs(d1-d2);
        ans=min(ans,360-ans);
        return ans;
    }
};