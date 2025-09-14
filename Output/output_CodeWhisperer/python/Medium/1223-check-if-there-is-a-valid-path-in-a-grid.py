#https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
#You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
#	1 which means a street connecting the left cell and the right cell.
#	2 which means a street connecting the upper cell and the lower cell.
#	3 which means a street connecting the left cell and the lower cell.
#	4 which means a street connecting the right cell and the lower cell.
#	5 which means a street connecting the left cell and the upper cell.
#	6 which means a street connecting the right cell and the upper cell.
#You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
#Notice that you are not allowed to change any street.
#Return true if there is a valid path in the grid or false otherwise.
# 
#Example 1:
#Input: grid = [[2,4,3],[6,5,2]]
#Output: true
#Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
#Example 2:
#Input: grid = [[1,2,1],[1,2,1]]
#Output: false
#Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
#Example 3:
#Input: grid = [[1,1,2]]
#Output: false
#Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
# 
#Constraints:
#	m == grid.length
#	n == grid[i].length
#	1 <= m, n <= 300
#	1 <= grid[i][j] <= 6
class Solution(object):
    def hasValidPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        if not grid:
            return False
            
        m, n = len(grid), len(grid[0])
        
        # Define valid connections for each street type
        # For each street type, store which directions it can connect to
        # [left, right, up, down]
        streets = {
            1: [[1,3,5], [1,3,5], [], []], # horizontal
            2: [[], [], [2,5,6], [2,5,6]], # vertical
            3: [[1,3,5], [], [], [2,5,6]], # left to down
            4: [[], [1,3,5], [], [2,5,6]], # right to down
            5: [[1,3,5], [], [2,5,6], []], # left to up
            6: [[], [1,3,5], [2,5,6], []]  # right to up
        }
        
        def is_valid(x, y):
            return 0 <= x < m and 0 <= y < n
        
        def can_connect(curr_x, curr_y, next_x, next_y):
            curr_street = grid[curr_x][curr_y]
            next_street = grid[next_x][next_y]
            
            # Determine direction of movement
            if next_x == curr_x - 1:  # moving up
                return next_street in streets[curr_street][2] and curr_street in streets[next_street][3]
            elif next_x == curr_x + 1:  # moving down
                return next_street in streets[curr_street][3] and curr_street in streets[next_street][2]
            elif next_y == curr_y - 1:  # moving left
                return next_street in streets[curr_street][0] and curr_street in streets[next_street][1]
            else:  # moving right
                return next_street in streets[curr_street][1] and curr_street in streets[next_street][0]
        
        def dfs(x, y, visited):
            if x == m-1 and y == n-1:
                return True
                
            visited.add((x, y))
            
            # Try all possible directions
            directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
            for dx, dy in directions:
                next_x, next_y = x + dx, y + dy
                if (is_valid(next_x, next_y) and 
                    (next_x, next_y) not in visited and 
                    can_connect(x, y, next_x, next_y)):
                    if dfs(next_x, next_y, visited):
                        return True
            
            return False
        
        return dfs(0, 0, set())
    