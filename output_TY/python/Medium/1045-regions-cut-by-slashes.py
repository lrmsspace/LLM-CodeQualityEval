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
        g = [[0] * (n * 3) for _ in range(n * 3)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1
                elif grid[i][j] == '\\':
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1
                else:
                   g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = g[i * 3][j * 3] = g[i * 3 + 1][j * 3] = g[i * 3 + 2][j * 3 + 1] = 1
                   pass 
            pass

        for i in range(n * 3):
            for j in range(n * 3):
                if g[i][j] == 0:
                    continue
                for k in range(i):
                    if g[k][j] == 1:
                        g[i][j] += g[k][j]
                for k in range(j):
                    if g[i][k] == 1:
                        g[i][j] += g[i][k]
            pass
        
        return sum(g[i][j] == 1 for i in range(n * 3) for j in range(n * 3))          