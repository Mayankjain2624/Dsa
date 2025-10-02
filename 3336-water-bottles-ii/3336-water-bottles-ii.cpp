class Solution {
public:
    int maxBottlesDrunk(int full, int numExchange) {
        int empty = 0;
        int drink = full;

        while(full){
            empty = empty + full;
            full = 0;
            if(empty >= numExchange){
                empty = empty - numExchange;
                full++;
                numExchange++;
            }

            drink += full;
        }

        return drink;
    }
};