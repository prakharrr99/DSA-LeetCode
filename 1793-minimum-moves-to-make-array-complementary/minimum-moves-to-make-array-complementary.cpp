class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int moves=INT_MAX;
        vector<int> diff(2*limit+2,0);

        for(int i=0;i<nums.size()/2;i++){
            int a=nums[i];
            int b=nums[nums.size()-i-1];
            int minval=min(a,b)+1;
            int maxval=max(a,b)+limit;

            diff[2]+=2;
            diff[2*limit+1]-=2;

            diff[minval]+=-1;
            diff[maxval+1]-=-1;

            diff[a+b]+=-1;
            diff[a+b+1]-=-1;

        }
        for(int i=2;i<=2*limit;i++){
            diff[i]+=diff[i-1];
        }
        for(int i=2;i<=2*limit;i++) moves=min(moves,diff[i]);
        return moves;

        // int moves=INT_MAX;
        // for(int i=2;i<=2*limit;i++){
        //     int c=0;
        //     for(int j=0;j<nums.size()/2;j++){
        //         int a=nums[j];
        //         int b=nums[nums.size()-j-1];
        //         if(a+b==i) continue;

        //         int minval=min(a,b)+1;
        //         int maxval=max(a,b)+limit;

        //         if(i>=minval && i<=maxval) c+=1;
        //         else c+=2;
        //     }
        //     moves=min(moves,c);
        // }
        // return moves;
    }
};