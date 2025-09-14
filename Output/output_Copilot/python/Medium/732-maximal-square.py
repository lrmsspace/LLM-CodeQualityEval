#https://leetcode.com/problems/maximal-square/
#Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
# 
#Example 1:
#Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
#Output: 4
#Example 2:
#Input: matrix = [["0","1"],["1","0"]]
#Output: 1
#Example 3:
#Input: matrix = [["0"]]
#Output: 0
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 300
#	matrix[i][j] is '0' or '1'.
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        rows, cols = len(matrix), len(matrix[0])
        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        max_side = 0

        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    max_side = max(max_side, dp[i][j])

        return max_side * max_side        