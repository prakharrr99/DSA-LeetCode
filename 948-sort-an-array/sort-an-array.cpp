class Solution {
public:
    void merge(vector<int>& nums,int start,int end){
        int mid=start+(end-start)/2;
        int n1=mid-start+1;
        int n2=end-mid;
        int* arr=new int[mid-start+1];
        int* brr=new int[end-mid];

        for(int i=0;i<n1;i++){
            arr[i]=nums[start+i];
        }
        for(int i=0;i<n2;i++){
            brr[i]=nums[mid+1+i];
        }
        int i=0;int j=0;
        int m=start;
        while(i<n1 && j<n2){
            if(arr[i]>brr[j]){
                nums[m++]=brr[j++];
            }
            else nums[m++]=arr[i++];
        }
        while(i<n1){
            nums[m++]=arr[i++];
        }
        while(j<n2){
            nums[m++]=brr[j++];
        }
        return;
    }
    void mergesort(vector<int>& nums,int start,int end){
        if(start>=end) return;
        int mid=start+(end-start)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        merge(nums,start,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};