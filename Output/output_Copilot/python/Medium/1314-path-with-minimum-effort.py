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
        left, right = 0, max(max(row) for row in heights) - min(min(row) for row in heights)

        def canReach(x):
            visited = [[False] * cols for _ in range(rows)]
            queue = [(0, 0)]
            visited[0][0] = True

            while queue:
                r, c = queue.pop(0)
                if r == rows - 1 and c == cols - 1:
                    return True
                for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and not visited[nr][nc]:
                        if abs(heights[nr][nc] - heights[r][c]) <= x:
                            visited[nr][nc] = True
                            queue.append((nr, nc))
            return False

        while left < right:
            mid = (left + right) // 2
            if canReach(mid):
                right = mid
            else:
                left = mid + 1

        return left        