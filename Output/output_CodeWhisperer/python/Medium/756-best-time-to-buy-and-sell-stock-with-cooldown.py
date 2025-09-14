#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#You are given an array prices where prices[i] is the price of a given stock on the ith day.
#Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
#	After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
#Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
# 
#Example 1:
#Input: prices = [1,2,3,0,2]
#Output: 3
#Explanation: transactions = [buy, sell, cooldown, buy, sell]
#Example 2:
#Input: prices = [1]
#Output: 0
# 
#Constraints:
#	1 <= prices.length <= 5000
#	0 <= prices[i] <= 1000
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1:
            return 0
        buy = [0] * len(prices)
        sell = [0] * len(prices)
        buy[0] = -prices[0]
        for i in range(1, len(prices)):
            buy[i] = max(buy[i-1], sell[i-2] - prices[i])
            sell[i] = max(sell[i-1], buy[i-1] + prices[i])
        return sell[-1]

        