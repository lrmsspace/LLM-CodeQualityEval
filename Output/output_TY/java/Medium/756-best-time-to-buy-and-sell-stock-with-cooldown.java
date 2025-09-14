/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/ */
//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
//	After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// 
//Example 1:
//Input: prices = [1,2,3,0,2]
//Output: 3
//Explanation: transactions = [buy, sell, cooldown, buy, sell]
//Example 2:
//Input: prices = [1]
//Output: 0
// 
//Constraints:
//	1 <= prices.length <= 5000
//	0 <= prices[i] <= 1000
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] dp = new int[n];
        int[] dp2 = new int[n];
        int[] dp3 = new int[n];
        int[] dp4 = new int[n];
        int[] dp5 = new int[n];
        int[] dp6 = new int[n];
        int[] dp7 = new int[n];
        int[] dp8 = new int[n];
        int[] dp9 = new int[n];
        int[] dp10 = new int[n];
        int[] dp11 = new int[n];
        int[] dp12 = new int[n];
        int[]dp13 = new int[n];
        int[] dp14 = new int[n];
        for(int i=0;i<n;i++){
            dp[i] = 0;
            dp2[i] = 0;
            dp3[i] = 0;
            dp4[i] = 0;
            dp5[i] = 0;
            dp6[i] = 0;
            dp7[i] = 0;
            dp8[i] = 0;
            dp9[i] = 0;
            dp10[i] = 0;
        }
        for(int i=0;i<n;i++){
            dp[i] = Math.max(dp[i-1],dp2[i-1]);
            dp2[i] = Math.max(dp2[i-1],dp3[i-1]);
            dp3[i] = Math.max(dp3[i-1],dp4[i-1]);
            dp4[i] = Math.max(dp4[i-1],dp5[i-1]);
            dp5[i] = Math.max(dp5[i-1],dp6[i-1]);
            dp6[i] = Math.max(dp6[i-1],dp7[i-1]);
            dp7[i] = Math.max(dp7[i-1],dp8[i-1]);
            dp8[i] = Math.max(dp8[i-1],dp9[i-1]);
            dp9[i] = Math.max(dp9[i-1],dp10[i-1]);
        }
        for(int i=0;i<n;i++){
            dp10[i] = Math.max(dp10[i-1],dp13[i-1]);
            dp13[i] = Math.max(dp13[i-1],dp14[i-1]);
        }
        return Math.max(dp[n-1],dp10[n-1]);

    }
}