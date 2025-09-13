#https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/
#Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
# 
#Example 1:
#Input: n = 2, m = 3
#Output: 3
#Explanation: 3 squares are necessary to cover the rectangle.
#2 (squares of 1x1)
#1 (square of 2x2)
#Example 2:
#Input: n = 5, m = 8
#Output: 5
#Example 3:
#Input: n = 11, m = 13
#Output: 6
# 
#Constraints:
#	1 <= n, m <= 13
class Solution(object):
    def tilingRectangle(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n == m:
            return 1
        if n > m:
            n, m = m, n
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if i == j:
                    dp[i][j] = 1
                elif i == 1:
                    dp[i][j] = j
                else:
                    dp[i][j] = float('inf')
                    for k in range(1, i // 2 + 1):
                        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j])
                    for k in range(1, j // 2 + 1):
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k])
        return dp[n][m]
        