#https://leetcode.com/problems/stamping-the-grid/
#You are given an m x n binary matrix grid where each cell is either 0 (empty) or 1 (occupied).
#You are then given stamps of size stampHeight x stampWidth. We want to fit the stamps such that they follow the given restrictions and requirements:
#	Cover all the empty cells.
#	Do not cover any of the occupied cells.
#	We can put as many stamps as we want.
#	Stamps can overlap with each other.
#	Stamps are not allowed to be rotated.
#	Stamps must stay completely inside the grid.
#Return true if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return false.
# 
#Example 1:
#Input: grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
#Output: true
#Explanation: We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
#Example 2:
#Input: grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
#Output: false 
#Explanation: There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.
# 
#Constraints:
#	m == grid.length
#	n == grid[r].length
#	1 <= m, n <= 105
#	1 <= m * n <= 2 * 105
#	grid[r][c] is either 0 or 1.
#	1 <= stampHeight, stampWidth <= 105
class Solution(object):
    def possibleToStamp(self, grid, stampHeight, stampWidth):
        """
        :type grid: List[List[int]]
        :type stampHeight: int
        :type stampWidth: int
        :rtype: bool
        """
        def is_valid(x, y):
            return 0 <= x < m and 0 <= y < n
        
        def dfs(x, y, stamp):
            for i in range(stampHeight):
                for j in range(stampWidth):
                    if stamp[i][j] == 1 and (x + i < 0 or y + j < 0 or x + i >= m or y + j >= n or grid[x + i][y + j] == 0):
                        return False
                    grid[x + i][y + j] += stamp[i][j]
            return True
        
        m, n = len(grid), len(grid[0])
        stamp = [[0] * stampWidth for _ in range(stampHeight)]
        for i in range(stampHeight):
            for j in range(stampWidth):
                stamp[i][j] = 1
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    if dfs(i, j, stamp):
                        return True
                    dfs(i, j, [[0] * stampWidth for _ in range(stampHeight)])
                    stamp = [[0] * stampWidth for _ in range(stampHeight)]
                    for k in range(stampHeight):
                        for l in range(stampWidth):
                            stamp[k][l] = 1 - stamp[k][l]
        
        return False
        