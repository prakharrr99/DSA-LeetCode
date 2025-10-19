#include<cmath>
class Solution {
private:
    void insertion(int a,string& ans,map<int,string>& m){

        if (m.find(a) != m.end()) {
            ans += m[a];
            return;
        }
        else if(a<4){
            while(a!=0){
                ans.push_back('I');
                a--;
            }
        }

        else if(a<9){
            ans.push_back('V');
            while(a!=5){
                ans.push_back('I');
                a--;
            }
        }
        else if(a<40){
            while(a!=0){
                ans.push_back('X');
                a=a-10;
            }
        }
        else if(a<90){
            ans.push_back('L');
            while(a!=50){
                ans.push_back('X');
                a=a-10;
            }
        }
        else if(a<400){
            while(a!=0){
                ans.push_back('C');
                a=a-100;
            }
        }
        else if(a<900){
            ans.push_back('D');
            while(a!=500){
                ans.push_back('C');
                a=a-100;
            }
        }
        else{
            while(a!=0){
                ans.push_back('M');
                a=a-1000;
            }
        }
        return;
    }
public:
    string intToRoman(int num) {
        map<int,string> m;
        m[1]="I";
        m[4]="IV";
        m[5]="V";
        m[9]="IX";
        m[10]="X";
        m[40]="XL";
        m[50]="L";
        m[90]="XC";
        m[100]="C";
        m[400]="CD";
        m[500]="D";
        m[900]="CM";
        m[1000]="M";

        int n=num; int count=0;
        while(num!=0){
            count=count+1;
            num=num/10;
        }

        string ans;
        while(n!=0){
            int p = 1;
            for (int i = 0; i < count-1; i++) p *= 10;
            int a=n/p;
            a=a*p;
            insertion(a,ans,m);
            n=n % p;
            count--;
        }
        return ans;
    }
};