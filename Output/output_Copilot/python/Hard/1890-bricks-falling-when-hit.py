#https://leetcode.com/problems/bricks-falling-when-hit/
#You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:
#	It is directly connected to the top of the grid, or
#	At least one other brick in its four adjacent cells is stable.
#You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).
#Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.
#Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.
# 
#Example 1:
#Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
#Output: [2]
#Explanation: Starting with the grid:
#[[1,0,0,0],
# [1,1,1,0]]
#We erase the underlined brick at (1,0), resulting in the grid:
#[[1,0,0,0],
# [0,1,1,0]]
#The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
#[[1,0,0,0],
# [0,0,0,0]]
#Hence the result is [2].
#Example 2:
#Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
#Output: [0,0]
#Explanation: Starting with the grid:
#[[1,0,0,0],
# [1,1,0,0]]
#We erase the underlined brick at (1,1), resulting in the grid:
#[[1,0,0,0],
# [1,0,0,0]]
#All remaining bricks are still stable, so no bricks fall. The grid remains the same:
#[[1,0,0,0],
# [1,0,0,0]]
#Next, we erase the underlined brick at (1,0), resulting in the grid:
#[[1,0,0,0],
# [0,0,0,0]]
#Once again, all remaining bricks are still stable, so no bricks fall.
#Hence the result is [0,0].
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 200
#	grid[i][j] is 0 or 1.
#	1 <= hits.length <= 4 * 104
#	hits[i].length == 2
#	0 <= xi <= m - 1
#	0 <= yi <= n - 1
#	All (xi, yi) are unique.
class Solution(object):
    def hitBricks(self, grid, hits):
        """
        :type grid: List[List[int]]
        :type hits: List[List[int]]
        :rtype: List[int]
        """
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if size[rootX] < size[rootY]:
                    rootX, rootY = rootY, rootX
                parent[rootY] = rootX
                size[rootX] += size[rootY]

        def index(i, j):
            return i * n + j + 1

        m, n = len(grid), len(grid[0])
        parent = [i for i in range(m * n + 2)]
        size = [0] * (m * n + 2)
        dummy = m * n
        dummy2 = m * n + 1

        for i in range(n):
            if grid[0][i] == 1:
                union(index(0, i), dummy)

        for i in range(1, m):
            for j in range(n):
                if grid[i][j] == 1:
                    if grid[i - 1][j] == 1:
                        union(index(i, j), index(i - 1, j))
                    if j > 0 and grid[i][j - 1] == 1:
                        union(index(i, j), index(i, j - 1))

        for i, j in hits:
            if grid[i][j] == 1:
                grid[i][j] = 0
                if i == 0:
                    union(index(i, j), dummy)
                else:
                    if grid[i - 1][j] == 1:
                        union(index(i, j), index(i - 1, j))
                    if j > 0 and grid[i][j - 1] == 1:
                        union(index(i, j), index(i, j - 1))
                    if j < n - 1 and grid[i][j + 1] == 1:
                        union(index(i, j), index(i, j + 1))

        result = []
        for i in range(len(hits) - 1, -1, -1):
            x, y = hits[i]
            if grid[x][y] == 0:
                grid[x][y] = 1
                if x        == 0:
                    union(index(x, y), dummy)
                else:
                    if grid[x - 1][y] == 1:
                        union(index(x, y), index(x - 1, y))
                    if y > 0 and grid[x][y - 1] == 1:
                        union(index(x, y), index(x, y - 1))
                    if y < n - 1 and grid[x][y + 1] == 1:
                        union(index(x, y), index(x, y + 1))
                if find(dummy) == find(index(x, y)):
                    result.append(size[find(index(x, y))] - 1)
                else:
                    result.append(0)
            else:
                result.append(0)
        return result[::-1]