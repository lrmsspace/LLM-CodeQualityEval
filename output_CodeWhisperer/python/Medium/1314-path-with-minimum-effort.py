#https://leetcode.com/problems/path-with-minimum-effort/
#You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
#A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
#Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
# 
#Example 1:
#Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
#Output: 2
#Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
#This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
#Example 2:
#Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
#Output: 1
#Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
#Example 3:
#Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
#Output: 0
#Explanation: This route does not require any effort.
# 
#Constraints:
#	rows == heights.length
#	columns == heights[i].length
#	1 <= rows, columns <= 100
#	1 <= heights[i][j] <= 106
class Solution(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        rows, cols = len(heights), len(heights[0])
        efforts = [[float('inf')] * cols for _ in range(rows)]
        efforts[0][0] = 0
        pq = [(0, 0, 0)]  # (effort, row, col)
        
        while pq:
            effort, row, col = heapq.heappop(pq)
            
            if row == rows - 1 and col == cols - 1:
                return effort
            
            for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                new_row, new_col = row + dr, col + dc
                
                if 0 <= new_row < rows and 0 <= new_col < cols:
                    new_effort = max(effort, abs(heights[new_row][new_col] - heights[row][col]))
                    
                    if new_effort < efforts[new_row][new_col]:
                        efforts[new_row][new_col] = new_effort
                        heapq.heappush(pq, (new_effort, new_row, new_col))
        
        return -1  # This should never happen if the input is valid
        