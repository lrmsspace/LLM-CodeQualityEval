#https://leetcode.com/problems/brick-wall/
#There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.
#Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
#Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
# 
#Example 1:
#Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
#Output: 2
#Example 2:
#Input: wall = [[1],[1],[1]]
#Output: 3
# 
#Constraints:
#	n == wall.length
#	1 <= n <= 104
#	1 <= wall[i].length <= 104
#	1 <= sum(wall[i].length) <= 2 * 104
#	sum(wall[i]) is the same for each row i.
#	1 <= wall[i][j] <= 231 - 1
class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        if not wall:
            return 0

        # Step 1: Calculate the total width of the wall
        total_width = sum(wall[0])

        # Step 2: Create a dictionary to count the number of bricks crossed at each position
        edge_count = {}
        for row in wall:
            width_sum = 0
            for brick in row[:-1]:        # Exclude the last brick in each row
                width_sum += brick
                if width_sum not in edge_count:
                    edge_count[width_sum] = 0   
                edge_count[width_sum] += 1

        # Step 3: Find the position with the maximum edges crossed
        max_edges = max(edge_count.values(), default=0)

        # Step 4: Calculate the minimum number of bricks crossed
        return len(wall) - max_edges

