#https://leetcode.com/problems/painting-a-grid-with-three-different-colors/
#You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
#Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.
# 
#Example 1:
#Input: m = 1, n = 1
#Output: 3
#Explanation: The three possible colorings are shown in the image above.
#Example 2:
#Input: m = 1, n = 2
#Output: 6
#Explanation: The six possible colorings are shown in the image above.
#Example 3:
#Input: m = 5, n = 5
#Output: 580986
# 
#Constraints:
#	1 <= m <= 5
#	1 <= n <= 1000
class Solution(object):
    def colorTheGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0] * 729 for _ in range(m + 1)]
        dp[0][0] = 1
        mod = 10 ** 9 + 7
        
        for i in range(1, m + 1):
            for j in range(729):
                for k in range(729):
                    if self.isValid(j, k):
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod
        
        return sum(dp[m]) % mod        