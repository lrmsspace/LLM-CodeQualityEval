/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ */
//You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
//Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// 
//Example 1:
//Input: k = 2, prices = [2,4,1]
//Output: 2
//Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//Example 2:
//Input: k = 2, prices = [3,2,6,5,0,3]
//Output: 7
//Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// 
//Constraints:
//	1 <= k <= 100
//	1 <= prices.length <= 1000
//	0 <= prices[i] <= 1000
int maxProfit(int k, int* prices, int pricesSize){
    int i, j, max, profit, n;
    int *buy, *sell;
    n = pricesSize;
    buy = (int *)malloc(sizeof(int) * (k + 1));
    sell = (int *)malloc(sizeof(int) * (k + 1));
    for (i = 0; i <= k; i++) {
        buy[i] = INT_MIN;
        sell[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= k; j++) {
            if (j == 0) {
                buy[j] = max(buy[j], -prices[i]);
                sell[j] = max(sell[j], 0);
            } else {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }
    }
    return sell[k];
}