class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(arr[mid]<arr[mid+1]){
                ans=mid+1;
                low=mid+1;
            }
            else{
                // ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};