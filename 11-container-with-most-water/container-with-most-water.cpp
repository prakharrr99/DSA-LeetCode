class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0; int area=0;
        int i=0;int j=height.size()-1;
        while(j>i){
            area=(j-i)*min(height[i],height[j]);
            maxi=max(maxi,area);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return maxi;
    }
};