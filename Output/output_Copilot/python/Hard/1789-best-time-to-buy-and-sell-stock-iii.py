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
        n = len(prices)
        if n < 2:
            return 0

        # dp[i][j]表示第i天结束时最多进行j次交易的最大利润
        dp = [[0] * 3 for _ in range(n)]

        # 第一天只能买入，不能卖出
        dp[0][0] = -prices[0]
        dp[0][1] = 0
        dp[0][2] = 0

        for i in range(1, n):
            for j in range(1, 3):
                # 第i天卖出，之前的状态是第i-1天买入
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i])
                # 第i天买入，之前的状态是第i-1天卖出
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - prices[i])

        return max(dp[n - 1])        