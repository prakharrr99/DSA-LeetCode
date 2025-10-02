class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink=numBottles;
        while(numBottles>=numExchange){
            numBottles=numBottles-numExchange;
            numExchange++;
            drink++;
            numBottles++;
        }
        return drink;
    }
};