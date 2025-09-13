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
        parent = [i for i in range(4 * n * n)]

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                parent[rootX] = rootY

        for i in range(n):
            for j in range(n):
                if grid[i][j] == '/':
                    union(4 * i * n + j, 4 * i * n + j + 1)
                    union(4 * i * n + j + 2, 4 * (i + 1) * n + j + 1)
                elif grid[i][j] == '\\':
                    union(4 * i * n + j, 4 * (i + 1) * n + j + 1)
                    union(4 * i * n + j + 1, 4 * (i + 1) * n + j)
                else:
                    union(4 * i * n + j, 4 * (i + 1) * n + j)
                    union(4 * i * n + j + 1, 4 * (i + 1) * n + j + 1)

        regions = set()
        for i in range(4 * n):
            regions.add(find(i))

        return len(regions)        