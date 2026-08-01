class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> m;
        for(auto it:planks){
            m[it]++;
        }
        vector<int> h;
        for(auto it:m){
            h.push_back(it.first);
        }
        int n=h.size();
        unordered_map<int,int> finall;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ht=h[i]+h[j];
                if(h[i]==h[j]) finall[ht]+=m[h[i]]/2;
                else finall[ht]+=min(m[h[i]],m[h[j]]);
            }
        }
        for(auto it:m){
            finall[it.first]+=it.second;
        }
        int ans=1;
        for(auto it:finall){
            ans=max(ans,it.second);
        }
        return ans;
    }
};