class Solution {
private:
    int sum(vector<int>& a){
        if(a.size()<3) return 0;
        return a[a.size()-1]+a[a.size()-2]+a[a.size()-3];
        // int m=INT_MIN;
        // for(int i=a.size()-1;i>=0;i--){
        //     if(m!=INT_MIN) return m;
        //     int j=i-1;
        //     int k=i-2;
        //     if(j<0 || k<0) return m;
        //     m=a[i]+a[j]+a[k];
        // }
        // return m;
    }
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> z;
        vector<int> o;
        vector<int> t;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0) z.push_back(nums[i]);
            else if(nums[i]%3==1) o.push_back(nums[i]);
            else t.push_back(nums[i]);
        }
        int s=INT_MIN;
        s=max(sum(z),s);
        s=max(sum(o),s);
        s=max(sum(t),s);
        if(z.size() && o.size() && t.size()) s=max(s,z[z.size()-1]+o[o.size()-1]+t[t.size()-1]);
        return s;
    }
};