class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftmax(height.size(),0);
        vector<int> rightmax(height.size(),0);

        leftmax[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            leftmax[i] = max(leftmax[i-1], height[i]);
        }
        rightmax[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        int water=0;
        for(int i=0;i<height.size();i++){
            int temp=min(leftmax[i],rightmax[i])-height[i];
            if(temp<0) temp=0;
            water+=temp;
        }
        return water;
    }
};