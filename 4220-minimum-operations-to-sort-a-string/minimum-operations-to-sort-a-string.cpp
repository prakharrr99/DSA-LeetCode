class Solution {
public:
    int minOperations(string s) {

        string x=s;
        sort(x.begin(),x.end());
        if(x==s) return 0;
        
        if(s.size()==2) return -1;
        if(s.size()==1) return 0;

        string s1=s;
        string s2=s;
        sort(s1.begin()+1,s1.end());
        sort(s2.begin(),s2.end()-1);
        if(x==s1 || x==s2) return 1;
        string s3=s1;
        string s4=s2;
        sort(s4.begin()+1,s4.end());
        sort(s3.begin(),s3.end()-1);
        if(s3==x || s4==x) return 2;

        return 3; 
    }
};