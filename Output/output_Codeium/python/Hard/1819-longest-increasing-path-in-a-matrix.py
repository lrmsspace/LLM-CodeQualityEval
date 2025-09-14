#https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#Given an m x n integers matrix, return the length of the longest increasing path in matrix.
#From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
# 
#Example 1:
#Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
#Output: 4
#Explanation: The longest increasing path is [1, 2, 6, 9].
#Example 2:
#Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
#Output: 4
#Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
#Example 3:
#Input: matrix = [[1]]
#Output: 1
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 200
#	0 <= matrix[i][j] <= 231 - 1
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]
        def dfs(i, j):
            if dp[i][j] != 0: return dp[i][j]
            val = matrix[i][j]
            max_len = 1
            for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                if 0 <= x < m and 0 <= y < n and matrix[x][y] > val:
                    max_len = max(max_len, 1 + dfs(x, y))
            dp[i][j] = max_len
            return max_len
        res = 0
        for i in range(m):
            for j in range(n):
                res = max(res, dfs(i, j))
        return res
