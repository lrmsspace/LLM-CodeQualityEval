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
        m, n = len(grid), len(grid[0])
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] == 1:
                    continue
                for x in xrange(max(0, i-stampHeight+1), min(m, i+1)):
                    for y in xrange(max(0, j-stampWidth+1), min(n, j+1)):
                        flag = True
                        for k in xrange(stampHeight):
                            for t in xrange(stampWidth):
                                nx, ny = x+k, y+t
                                if nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] == 1:
                                    flag = False
                                    break
                            if not flag:
                                break
                        if flag:
                            break
                    if flag:
                        break
                if not flag:
                    return False
        return True
