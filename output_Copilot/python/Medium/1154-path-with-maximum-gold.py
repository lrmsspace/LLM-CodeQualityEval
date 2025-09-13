#https://leetcode.com/problems/path-with-maximum-gold/
#In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
#Return the maximum amount of gold you can collect under the conditions:
#	Every time you are located in a cell you will collect all the gold in that cell.
#	From your position, you can walk one step to the left, right, up, or down.
#	You can't visit the same cell more than once.
#	Never visit a cell with 0 gold.
#	You can start and stop collecting gold from any position in the grid that has some gold.
# 
#Example 1:
#Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
#Output: 24
#Explanation:
#[[0,6,0],
# [5,8,7],
# [0,9,0]]
#Path to get the maximum gold, 9 -> 8 -> 7.
#Example 2:
#Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
#Output: 28
#Explanation:
#[[1,0,7],
# [2,0,6],
# [3,4,5],
# [0,3,0],
# [9,0,20]]
#Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 15
#	0 <= grid[i][j] <= 100
#	There are at most 25 cells containing gold.
class Solution(object):
    def getMaximumGold(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # 1. 使用 DFS 遍历所有路径，计算每条路径的金子数量
        # 2. 使用 visited 数组记录访问过的格子，避免重复访问
        # 3. 时间复杂度 O(4^k)，空间复杂度 O(k)，k 为金子的数量
        # 4. 使用回溯算法，遍历所有可能的路径，计算最大金子数量
        # 5. 返回最大金子数量
        # 6. 时间复杂度 O(m*n)，空间复杂度 O(m*n)
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        max_gold = 0
        
        def dfs(x, y, gold):
            nonlocal max_gold
            max_gold = max(max_gold, gold)
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] > 0:
                    temp = grid[nx][ny]
                    grid[nx][ny] = 0
                    dfs(nx, ny, gold + temp)
                    grid[nx][ny] = temp
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] > 0:
                    temp = grid[i][j]
                    grid[i][j] = 0
                    dfs(i, j, temp)
                    grid[i][j] = temp
        
        return max_gold