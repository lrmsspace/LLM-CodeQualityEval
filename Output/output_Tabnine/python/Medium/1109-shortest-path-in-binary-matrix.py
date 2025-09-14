#https://leetcode.com/problems/shortest-path-in-binary-matrix/
#Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
#A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
#	All the visited cells of the path are 0.
#	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
#The length of a clear path is the number of visited cells of this path.
# 
#Example 1:
#Input: grid = [[0,1],[1,0]]
#Output: 2
#Example 2:
#Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
#Output: 4
#Example 3:
#Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
#Output: -1
# 
#Constraints:
#	n == grid.length
#	n == grid[i].length
#	1 <= n <= 100
#	grid[i][j] is 0 or 1
class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # Initialize a queue with the starting cell and its distance from the starting cell
        queue = [(0, 0, 1)]
        
        # Initialize a visited set to keep track of visited cells
        visited = set([(0, 0)])
        
        # Define the four possible directions for traversal
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1)]
        
        # Loop until the queue is empty
        while queue:
            # Dequeue a cell from the queue
            x, y, distance = queue.pop(0)
            
            # Check if the current cell is the destination cell
            if x == len(grid) - 1 and y == len(grid[0]) - 1:
                return distance
            
            # Iterate through the four possible directions
            for dx, dy in directions:
                # Calculate the new cell coordinates
                new_x, new_y = x + dx, y + dy
                
                # Check if the new cell coordinates are valid and within the grid boundaries
                if 0 <= new_x < len(grid) and 0 <= new_y < len(grid[0]) and grid[new_x][new_y] == 0 and (new_x, new_y) not in visited:
                    # Add the new cell to the queue and the visited set
                    queue.append((new_x, new_y, distance + 1))
                    visited.add((new_x, new_y))
                # If the destination cell is reached, return the distance
                if new_x == len(grid) - 1 and new_y == len(grid[0]) - 1:
                    return distance
        
        # If no clear path is found, return -1

            
        