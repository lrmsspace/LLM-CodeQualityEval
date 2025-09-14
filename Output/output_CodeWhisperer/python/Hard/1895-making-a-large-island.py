#https://leetcode.com/problems/making-a-large-island/
#You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
#Return the size of the largest island in grid after applying this operation.
#An island is a 4-directionally connected group of 1s.
# 
#Example 1:
#Input: grid = [[1,0],[0,1]]
#Output: 3
#Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
#Example 2:
#Input: grid = [[1,1],[1,0]]
#Output: 4
#Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
#Example 3:
#Input: grid = [[1,1],[1,1]]
#Output: 4
#Explanation: Can't change any 0 to 1, only one island with area = 4.
# 
#Constraints:
#	n == grid.length
#	n == grid[i].length
#	1 <= n <= 500
#	grid[i][j] is either 0 or 1.
class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        
        # Function to check if a position is valid  
        def valid(r, c):
            return 0 <= r < n and 0 <= c < n
        
        # DFS to mark islands with unique IDs and return size
        def dfs(r, c, index):
            if not valid(r, c) or grid[r][c] != 1:
                return 0
            grid[r][c] = index
            size = 1
            for nr, nc in [(r+1,c), (r-1,c), (r,c+1), (r,c-1)]:
                size += dfs(nr, nc, index)
            return size
        
        # Map to store island index -> size
        island_sizes = {0: 0}  # 0 represents water
        
        # First pass: label each island with unique index and get sizes
        index = 2  # Start from 2 since 0 is water and 1 is unvisited land
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    island_sizes[index] = dfs(i, j, index)
                    index += 1
        
        # Handle case where grid is all 1's
        if len(island_sizes) == 1:  # Only contains the 0 entry
            return n * n
        
        # Second pass: try to connect islands
        max_size = max(island_sizes.values())
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:  # Found water cell
                    # Get neighboring islands
                    neighbors = set()
                    for ni, nj in [(i+1,j), (i-1,j), (i,j+1), (i,j-1)]:
                        if valid(ni, nj):
                            neighbors.add(grid[ni][nj])
                    
                    # Calculate size if we change this cell to 1
                    size = 1  # Count current cell
                    for neighbor in neighbors:
                        size += island_sizes[neighbor]
                    max_size = max(max_size, size)
        
        return max_size
