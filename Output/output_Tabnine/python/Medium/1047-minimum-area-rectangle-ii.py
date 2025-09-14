#https://leetcode.com/problems/minimum-area-rectangle-ii/
#You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
#Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
#Answers within 10-5 of the actual answer will be accepted.
# 
#Example 1:
#Input: points = [[1,2],[2,1],[1,0],[0,1]]
#Output: 2.00000
#Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
#Example 2:
#Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
#Output: 1.00000
#Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
#Example 3:
#Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
#Output: 0
#Explanation: There is no possible rectangle to form from these points.
# 
#Constraints:
#	1 <= points.length <= 50
#	points[i].length == 2
#	0 <= xi, yi <= 4 * 104
#	All the given points are unique.
class Solution(object):
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        # Sort the points by x-coordinate and y-coordinate.
        points.sort()
        
        # Initialize a dictionary to store the vertical lines and their corresponding horizontal lines.
        lines = {}
        
        # Initialize the minimum area as infinity.
        min_area = float('inf')
        
        # Iterate through the sorted points.
        for i in range(len(points) - 1):
            x1, y1 = points[i]
            x2, y2 = points[i + 1]
            
            # Check if the vertical line connecting (x1, y1) and (x2, y2) already exists.
            if (x1, y1) in lines:
                # Get the horizontal lines connected to the vertical line.
                horizontal_lines = lines[(x1, y1)]
                
                # Iterate through the horizontal lines.
                for horizontal_line in horizontal_lines:
                    # Calculate the area of the rectangle formed by the vertical line and the horizontal line.
                    area = abs(x2 - x1) * abs(horizontal_line[1] - y1)
                    
                    # Update the minimum area if necessary.
                    min_area = min(min_area, area)
        
        # Return the minimum area.
        return min_area if min_area!= float('inf') else 0.0 
        