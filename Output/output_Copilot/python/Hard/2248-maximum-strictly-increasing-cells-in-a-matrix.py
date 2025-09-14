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
        from collections import defaultdict
        from sortedcontainers import SortedList

        m, n = len(mat), len(mat[0])
        dp = [[1] * n for _ in range(m)]
        cells = defaultdict(list)

        for i in range(m):
            for j in range(n):
                cells[mat[i][j]].append((i, j))

        max_cells = 0
        sorted_keys = SortedList(cells.keys())

        for key in sorted_keys:
            for i, j in cells[key]:
                for k in range(i + 1, m):
                    if mat[k][j] > key:
                        dp[k][j] = max(dp[k][j], dp[i][j] + 1)
                for k in range(j + 1, n):
                    if mat[i][k] > key:
                        dp[i][k] = max(dp[i][k], dp[i][j] + 1)
                max_cells = max(max_cells, dp[i][j])

        return max_cells        