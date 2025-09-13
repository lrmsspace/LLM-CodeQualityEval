#https://leetcode.com/problems/perfect-rectangle/
#Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
#Return true if all the rectangles together form an exact cover of a rectangular region.
# 
#Example 1:
#Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
#Output: true
#Explanation: All 5 rectangles together form an exact cover of a rectangular region.
#Example 2:
#Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
#Output: false
#Explanation: Because there is a gap between the two rectangular regions.
#Example 3:
#Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
#Output: false
#Explanation: Because two of the rectangles overlap with each other.
# 
#Constraints:
#	1 <= rectangles.length <= 2 * 104
#	rectangles[i].length == 4
#	-105 <= xi < ai <= 105
#	-105 <= yi < bi <= 105
class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        # Initialize the minimum and maximum values for x and y
        min_x, min_y, max_x, max_y = float('inf'), float('inf'), float('-inf'), float('-inf')
        
        # Calculate the total area of the rectangles
        total_area = 0
        
        # Count the number of rectangles
        num_rectangles = 0
        
        # Initialize the number of occurrences of each corner
        corners = {}
        
        # Iterate through each rectangle
        for x1, y1, x2, y2 in rectangles:
            min_x = min(min_x, x1)
            min_y = min(min_y, y1)
            max_x = max(max_x, x2)
            max_y = max(max_y, y2)
            
            total_area += (x2 - x1) * (y2 - y1)
            
            # Count the occurrences of each corner
            corners[(x1, y1)] = corners.get((x1, y1), 0) + 1
            corners[(x2, y1)] = corners.get((x2, y1), 0) + 1
            corners[(x1, y2)] = corners.get((x1, y2), 0) + 1
            corners[(x2, y2)] = corners.get((x2, y2), 0) - 1
            
            num_rectangles += 1
        
        # Check if the total area matches the calculated area
        if total_area!= (max_x - min_x) * (max_y - min_y):
            return False
        
        # Check if all corners occur an even number of times
        for x, y in corners.keys():
            if corners[(x, y)] % 2!= 0:
                return False
        
        # Check if the number of rectangles matches the calculated number
        if num_rectangles!= len(corners) // 4:
            return False
        
        return True
        