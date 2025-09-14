#https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/
#Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.
#From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.
#Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.
#Return an integer denoting the maximum number of cells that can be visited.
# 
#Example 1:
#Input: mat = [[3,1],[3,4]]
#Output: 2
#Explanation: The image shows how we can visit 2 cells starting from row 1, column 2. It can be shown that we cannot visit more than 2 cells no matter where we start from, so the answer is 2. 
#Example 2:
#Input: mat = [[1,1],[1,1]]
#Output: 1
#Explanation: Since the cells must be strictly increasing, we can only visit one cell in this example. 
#Example 3:
#Input: mat = [[3,1,6],[-9,5,7]]
#Output: 4
#Explanation: The image above shows how we can visit 4 cells starting from row 2, column 1. It can be shown that we cannot visit more than 4 cells no matter where we start from, so the answer is 4. 
# 
#Constraints:
#	m == mat.length 
#	n == mat[i].length 
#	1 <= m, n <= 105
#	1 <= m * n <= 105
#	-105 <= mat[i][j] <= 105
class Solution(object):
    def maxIncreasingCells(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        dp = [[0] * n for _ in range(m)]
        row_max = [0] * m
        col_max = [0] * n
        cell_map = {}
        for i in range(m):
            for j in range(n):
                cell_map.setdefault(mat[i][j], []).append((i, j))
        for num in sorted(cell_map.keys()):
            for i, j in cell_map[num]:
                dp[i][j] = max(row_max[i], col_max[j]) + 1
            for i, j in cell_map[num]:
                row_max[i] = max(row_max[i], dp[i][j])
                col_max[j] = max(col_max[j], dp[i][j])
        return max(max(row) for row in dp)
        