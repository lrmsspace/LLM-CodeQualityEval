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
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) {
        return 0;
    }
    int* buy = (int*)malloc(sizeof(int) * pricesSize);
    int* sell = (int*)malloc(sizeof(int) * pricesSize);
    buy[0] = -prices[0];
    sell[0] = 0;
    for (int i = 1; i < pricesSize; i++) {
        buy[i] = (buy[i - 1] > sell[i - 1] - prices[i] ? buy[i - 1] : sell[i - 1] - prices[i]);
        sell[i] = (sell[i - 1] > buy[i - 1] + prices[i] ? sell[i - 1] : buy[i - 1] + prices[i]);
    }
    int result = sell[pricesSize - 1];
    free(buy);
    free(sell);
    return result;
}