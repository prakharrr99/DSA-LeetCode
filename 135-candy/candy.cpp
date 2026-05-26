class Solution {
public:
    int candy(vector<int>& ratings) {
        int required_c=0;
        
        vector<int> f(ratings.size(),1);

        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
                f[i]=f[i-1]+1;
            }
        }

        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                if(f[i+1]>=f[i]) f[i]=f[i+1]+1;
            }
        }

        for(auto it:f) required_c+=it;
        return required_c;
    }
};