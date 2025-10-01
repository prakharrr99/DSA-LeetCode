class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink=numBottles;

        while(numBottles>=numExchange){
            drink=drink+numBottles/numExchange;
            int remaining=numBottles%numExchange;
            numBottles=remaining+numBottles/numExchange;
        }
        return drink;
    }
};