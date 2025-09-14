#https://leetcode.com/problems/regions-cut-by-slashes/
#An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
#Given the grid grid represented as a string array, return the number of regions.
#Note that backslash characters are escaped, so a '\' is represented as '\\'.
# 
#Example 1:
#Input: grid = [" /","/ "]
#Output: 2
#Example 2:
#Input: grid = [" /","  "]
#Output: 1
#Example 3:
#Input: grid = ["/\\","\\/"]
#Output: 5
#Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
# 
#Constraints:
#	n == grid.length == grid[i].length
#	1 <= n <= 30
#	grid[i][j] is either '/', '\', or ' '.
class Solution(object):
    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        def dfs(r, c, d):
            if r < 0 or r >= n or c < 0 or c >= n or grid[r][c]!= d:
                return
            grid[r][c] = '0'
            dfs(r - 1, c, '/')
            dfs(r + 1, c, '/')
            dfs(r, c - 1, '\\')
            dfs(r, c + 1, '/')
        
        n = len(grid)
        count = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j]!= '0':
                    dfs(i, j, grid[i][j])
                    count += 1
        return count
        