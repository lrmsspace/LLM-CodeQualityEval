/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ */
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//Find the maximum profit you can achieve. You may complete at most two transactions.
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// 
//Example 1:
//Input: prices = [3,3,5,0,0,3,1,4]
//Output: 6
//Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//Example 2:
//Input: prices = [1,2,3,4,5]
//Output: 4
//Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
//Example 3:
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transaction is done, i.e. max profit = 0.
// 
//Constraints:
//	1 <= prices.length <= 105
//	0 <= prices[i] <= 105
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n < 2) {
            return 0;
        }
        int[][] dp = new int[n][5];
        dp[0][0] = -prices[0]; // Buy first stock
        dp[0][1] = 0;         // Sold first stock
        dp[0][2] = -prices[0]; // Buy second stock
        dp[0][3] = 0;         // Sold second stock
        dp[0][4] = 0;         // No transaction

        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][4] - prices[i]); // Buy first stock
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // Sold first stock
            dp[i][2] = Math.max(dp[i - 1][2], dp[i - 1][1] - prices[i]); // Buy second stock
            dp[i][3] = Math.max(dp[i - 1][3], dp[i - 1][2] + prices[i]); // Sold second stock
            dp[i][4] = Math.max(dp[i - 1][4], dp[i - 1][3]);             // No transaction
        }

        return Math.max(dp[n - 1][3], dp[n - 1][4]);        
    }
}