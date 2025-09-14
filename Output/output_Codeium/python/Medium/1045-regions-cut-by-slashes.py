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
        graph = [[0] * (n * 3) for _ in range(n * 3)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    graph[i * 3][j * 3 + 2] = graph[i * 3 + 1][j * 3 + 1] = graph[i * 3 + 2][j * 3] = 1
                if grid[i][j] == '\\':
                    graph[i * 3][j * 3] = graph[i * 3 + 1][j * 3 + 1] = graph[i * 3 + 2][j * 3 + 2] = 1

        def dfs(i, j):
            if 0 <= i < n * 3 and 0 <= j < n * 3 and not graph[i][j]:
                graph[i][j] = 1
                dfs(i - 1, j)
                dfs(i + 1, j)
                dfs(i, j - 1)
                dfs(i, j + 1)

        res = 0
        for i in range(n * 3):
            for j in range(n * 3):
                if not graph[i][j]:
                    dfs(i, j)
                    res += 1
        return res
