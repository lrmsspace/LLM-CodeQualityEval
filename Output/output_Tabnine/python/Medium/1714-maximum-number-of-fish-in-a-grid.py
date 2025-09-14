#https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
#You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
#	A land cell if grid[r][c] = 0, or
#	A water cell containing grid[r][c] fish, if grid[r][c] > 0.
#A fisher can start at any water cell (r, c) and can do the following operations any number of times:
#	Catch all the fish at cell (r, c), or
#	Move to any adjacent water cell.
#Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
#An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
# 
#Example 1:
#Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
#Output: 7
#Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
#Example 2:
#Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
#Output: 1
#Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 10
#	0 <= grid[i][j] <= 10
class Solution(object):
    def findMaxFish(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        max_fish = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    fish = grid[i][j]
                    grid[i][j] = 0
                    for dx, dy in directions:
                        new_i, new_j = i + dx, j + dy
                        if 0 <= new_i < m and 0 <= new_j < n and grid[new_i][new_j] > 0:
                            max_fish = max(max_fish, fish + grid[new_i][new_j])
                            grid[new_i][new_j] = 0
                    max_fish = max(max_fish, fish)
        return max_fish