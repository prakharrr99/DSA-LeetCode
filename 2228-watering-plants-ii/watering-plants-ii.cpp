class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i=0; int j=plants.size()-1; 
        int cana=capacityA; int canb=capacityB;
        int a=0;
        while(j>i){
            if(cana>=plants[i]){
                cana-=plants[i++];
            }
            else{
                a++;
                cana=capacityA;
                cana-=plants[i++];
            }
            // no need to check i and j equivalence here 
            if(canb>=plants[j]){
                canb-=plants[j--];
            }
            else{
                a++;
                canb=capacityB;
                canb-=plants[j--];
            }
        }
        if (i==j && max(cana, canb) < plants[i]) a++;
        return a;
    }
};