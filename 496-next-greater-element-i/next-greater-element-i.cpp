class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> a(nums2.size(),-1);
        stack<int> s;
        for(int i=0;i<nums2.size();i++){
            while(s.size()!=0 && nums2[s.top()]<nums2[i]){
                a[s.top()]=nums2[i];
                s.pop();
            }
            s.push(i);
        }

        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
        }
        vector<int> b;
        for(int i=0;i<nums1.size();i++){
            b.push_back(a[m[nums1[i]]]);
        }

        return b;
    }
};