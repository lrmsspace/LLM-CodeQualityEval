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
int maxProfit(int* prices, int pricesSize){
    int profit[pricesSize][3];
    profit[0][0] = 0;
    profit[0][1] = -prices[0];
    profit[0][2] = -prices[0];
    for (int i = 1; i < pricesSize; i++) {
        profit[i][0] = profit[i - 1][0];
    }
    for (int i = 1; i < pricesSize; i++) {
        profit[i][1] = fmax(profit[i - 1][1], profit[i - 1][2] + prices[i]);
    }
    for (int i = 2; i < pricesSize; i++) {
        profit[i][2] = fmax(profit[i - 1][2], profit[i - 2][0] - prices[i]);
    }
    return profit[pricesSize - 1][0];
}