/**https://leetcode.com/problems/water-bottles/ */
//There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
//The operation of drinking a full water bottle turns it into an empty bottle.
//Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.
// 
//Example 1:
//Input: numBottles = 9, numExchange = 3
//Output: 13
//Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
//Number of water bottles you can drink: 9 + 3 + 1 = 13.
//Example 2:
//Input: numBottles = 15, numExchange = 4
//Output: 19
//Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
//Number of water bottles you can drink: 15 + 3 + 1 = 19.
// 
//Constraints:
//	1 <= numBottles <= 100
//	2 <= numExchange <= 100
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles; // Total number of bottles consumed
        int emptyBottles = numBottles; // Number of empty bottles we have

        // While we have enough empty bottles to exchange for at least one full bottle
        while (emptyBottles >= numExchange) {
            // Calculate how many new full bottles we can get from the empty ones
            int newFullBottles = emptyBottles / numExchange;
            total += newFullBottles; // Add the new full bottles to the total consumed
            emptyBottles = emptyBottles % numExchange + newFullBottles; // Update the count of empty bottles
        }

        return total; // Return the total number of bottles consumed        
    }
}