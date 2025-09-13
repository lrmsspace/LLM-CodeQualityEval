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
        n = len(grid)
        def dfs(i, j):
            if min(i, j) < 0 or max(i, j) >= 4*n or grid[i][j] != 0:
                return
            grid[i][j] = 1
            dfs(i-1, j)
            dfs(i+1, j)
            dfs(i, j-1)
            dfs(i, j+1)
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    grid.append(list(' '*4*n))
                    grid.append(list(' '*4*n))
                    for k in range(4):
                        grid[2*i+1][4*j+k] = ['\\', '/', ' ', ' '][k]
                elif grid[i][j] == '\\':
                    grid.append(list(' '*4*n))
                    grid.append(list(' '*4*n))

        