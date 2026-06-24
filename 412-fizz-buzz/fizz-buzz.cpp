class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for(int j=1;j<=n;j++){
            string s=to_string(j);
            if(j%3==0 && j%5==0) v.push_back("FizzBuzz");
            else if(j%3==0) v.push_back("Fizz");
            else if(j%5==0) v.push_back("Buzz");
            else v.push_back(s);
        }
        return v;
    }
};