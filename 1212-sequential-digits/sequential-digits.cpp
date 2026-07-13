class Solution {
public:
    void f(string d,vector<int>& ans,int high){
        while(stoi(d)<=high){
            ans.push_back(stoi(d));
            if(d[d.size()-1]=='9') break;
            for(int i=0;i<d.size();i++){
                d[i]++;
            }
        }
        return ;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        f("12",ans,1000000000);
        f("123",ans,1000000000);
        f("1234",ans,1000000000);
        f("12345",ans,1000000000);
        f("123456",ans,1000000000);
        f("1234567",ans,1000000000);
        f("12345678",ans,1000000000);
        ans.push_back(123456789);

        for(auto it:ans){
            cout<<it<<" ";
        }
        vector<int> a;
        for(auto it:ans){
            if(it>=low && high>=it) a.push_back(it);
            
        }
        return a;
    }
};