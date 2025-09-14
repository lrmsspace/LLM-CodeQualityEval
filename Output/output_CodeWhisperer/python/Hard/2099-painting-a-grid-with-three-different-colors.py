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
        MOD = 1000000007
        def dfs(i, j, prev_row, prev_col, prev_prev_row, prev_prev_col):
            if i == m:
                return 1
            key = (i, prev_row, prev_col, prev_prev_row, prev_prev_col)
            if key in memo:
                return memo[key]
            ans = 0
            for color in range(3):
                if color != prev_row and color != prev_prev_row and (i == 0 or color != prev_col):
                    ans = (ans + dfs(i + 1, color, color, prev_row, prev_col)) % MOD
            memo[key] = ans
            return ans
        
        memo = {}
        return dfs(0, -1, -1, -1, -1, -1)
        