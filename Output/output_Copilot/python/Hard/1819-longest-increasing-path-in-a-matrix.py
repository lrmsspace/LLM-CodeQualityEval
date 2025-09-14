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
        if not matrix:
            return 0

        rows, cols = len(matrix), len(matrix[0])
        dp = [[1] * cols for _ in range(rows)]   
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        max_length = 1
        visited = set()
        stack = []
        for i in range(rows):
            for j in range(cols):
                stack.append((i, j))
        while stack:
            x, y = stack.pop()
            visited.add((x, y))
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < rows and 0 <= ny < cols and matrix[nx][ny] > matrix[x][y]:
                    dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1)
                    max_length = max(max_length, dp[nx][ny])
                    if (nx, ny) not in visited:
                        stack.append((nx, ny))
        return max_length     