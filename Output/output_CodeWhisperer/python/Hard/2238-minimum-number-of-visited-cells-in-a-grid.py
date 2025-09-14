#https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/
#You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).
#Starting from the cell (i, j), you can move to one of the following cells:
#	Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
#	Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
#Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.
# 
#Example 1:
#Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
#Output: 4
#Explanation: The image above shows one of the paths that visits exactly 4 cells.
#Example 2:
#Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
#Output: 3
#Explanation: The image above shows one of the paths that visits exactly 3 cells.
#Example 3:
#Input: grid = [[2,1,0],[1,0,0]]
#Output: -1
#Explanation: It can be proven that no path exists.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 105
#	1 <= m * n <= 105
#	0 <= grid[i][j] < m * n
#	grid[m - 1][n - 1] == 0
class Solution(object):
    def minimumVisitedCells(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        q = deque([(0, 0)])
        visited = set([(0, 0)])
        steps = 1
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                if i == m - 1 and j == n - 1:
                    return steps
                for k in range(j + 1, min(n, j + grid[i][j] + 1)):
                    if (i, k) not in visited:
                        q.append((i, k))
                        visited.add((i, k))
                for k in range(i + 1, min(m, i + grid[i][j] + 1)):
                    if (k, j) not in visited:
                        q.append((k, j))
                        visited.add((k, j))
            steps += 1
        return -1
        