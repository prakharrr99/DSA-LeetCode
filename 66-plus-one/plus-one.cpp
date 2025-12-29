class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]!=9){
            digits[digits.size()-1]+=1;
            return digits;
        }

        vector<int> ans;
        int i=digits.size()-1;
        while(i>=0 && digits[i]==9){
            ans.push_back(0);
            digits[i]=0;
            i--;
        }
        if(i<0){
             ans.insert(ans.begin(),1); return ans;
        }
        else{
             digits[i]+=1; return digits;
        }

        // int c=1;
        // vector<int> ans;
        
        // ans.push_back(0);

        // for(int i=digits.size()-2;i>=0;i--){
        //     if(digits[i]==9){
        //         int a=(digits[i]+c)%10;
        //         ans.insert(ans.begin(),a);
        //     }
        //     else{
        //         ans.insert(ans.begin(),digits[i]+c);
        //         c=0;
        //     }
        // }
        // if(c!=0) ans.insert(ans.begin(),1);
        // return ans;
    }
};