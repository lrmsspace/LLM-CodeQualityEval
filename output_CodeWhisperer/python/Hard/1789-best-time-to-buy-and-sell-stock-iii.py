#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#You are given an array prices where prices[i] is the price of a given stock on the ith day.
#Find the maximum profit you can achieve. You may complete at most two transactions.
#Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
# 
#Example 1:
#Input: prices = [3,3,5,0,0,3,1,4]
#Output: 6
#Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
#Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
#Example 2:
#Input: prices = [1,2,3,4,5]
#Output: 4
#Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
#Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
#Example 3:
#Input: prices = [7,6,4,3,1]
#Output: 0
#Explanation: In this case, no transaction is done, i.e. max profit = 0.
# 
#Constraints:
#	1 <= prices.length <= 105
#	0 <= prices[i] <= 105
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        n = len(prices)
        # max profit in 0 transactions
        g = [0] * n
        # max profit in 1 transactions
        l = [0] * n
        # max profit in 2 transactions
        h = [0] * n
        for i in range(1, n):
            diff = prices[i] - prices[i-1]
            l[i] = max(l[i-1] + diff, g[i-1] + diff, diff)
            g[i] = max(g[i-1], l[i])
            h[i] = max(h[i-1], g[i-1] + diff)
        return max(h[n-1], g[n-1])
        