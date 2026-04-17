class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n!=0){
            int a=n%10;
            if(ans>INT_MAX/10) return -1;
            ans=ans*10+a;
            n=n/10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int d=INT_MAX;
        unordered_map<int,int> m;
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            
            int r=reverse(nums[i]);
            a.push_back(r);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(m.find(a[i])!=m.end()){
                // if(i<m[a[i]]) 
                d=min(d,abs(i-m[a[i]]));
            }
            m[nums[i]]=i;
        }
        if(d==INT_MAX) return -1;
        return d;
    }
};