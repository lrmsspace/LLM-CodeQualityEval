/**https://leetcode.com/problems/coin-change/ */
//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//You may assume that you have an infinite number of each kind of coin.
// 
//Example 1:
//Input: coins = [1,2,5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
//Example 2:
//Input: coins = [2], amount = 3
//Output: -1
//Example 3:
//Input: coins = [1], amount = 0
//Output: 0
// 
//Constraints:
//	1 <= coins.length <= 12
//	1 <= coins[i] <= 231 - 1
//	0 <= amount <= 104
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    // Initialize a dp array with size amount + 1 and fill it with infinity
    const dp = Array(amount + 1).fill(Infinity);
    dp[0] = 0; // Base case: 0 coins needed for 0 amount
    
    // Iterate through all possible amounts
    for (let i = 1; i <= amount; i++) {
        // Iterate through all possible coins
        for (let coin of coins) {
            // If the current coin can make up the current amount, update the minimum number of coins needed
            if (coin <= i) {
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    // If no combination of coins can make up the amount, return -1
    return dp[amount] === Infinity? -1 : dp[amount];
    
};