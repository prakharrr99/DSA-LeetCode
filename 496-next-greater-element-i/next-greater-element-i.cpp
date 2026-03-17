class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
        }
        vector<int> a;
        for(int i=0;i<nums1.size();i++){
            stack<int> s;
            s.push(nums1[i]);
            int j=m[nums1[i]]+1;
            int b=0;
            while(j<nums2.size()){
                if(s.top()<nums2[j]){
                    a.push_back(nums2[j]); b=1;
                    break;
                }
                j++;
            }
            if(b==0) a.push_back(-1);
        }
        return a;
    }
};