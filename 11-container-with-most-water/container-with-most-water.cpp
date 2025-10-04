class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; int j=height.size()-1; int water=0;
        while(j>i){
            int newarea=min(height[i],height[j])*(j-i);
            water=max(water,newarea);
            if(height[i]<height[j]) i++;
            else if(height[i]>height[j]) j--;
            else{
                i++; j--;
            }
        }
        return water;
    }
};