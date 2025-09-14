#https://leetcode.com/problems/rectangle-area/
#Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
#The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
#The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).
# 
#Example 1:
#Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
#Output: 45
#Example 2:
#Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
#Output: 16
# 
#Constraints:
#	-104 <= ax1 <= ax2 <= 104
#	-104 <= ay1 <= ay2 <= 104
#	-104 <= bx1 <= bx2 <= 104
#	-104 <= by1 <= by2 <= 104
class Solution(object):
    def computeArea(self, ax1, ay1, ax2, ay2, bx1, by1, bx2, by2):
        """
        :type ax1: int
        :type ay1: int
        :type ax2: int
        :type ay2: int
        :type bx1: int
        :type by1: int
        :type bx2: int
        :type by2: int
        :rtype: int
        """
        # Calculate the area of each rectangle
        area1 = (ax2 - ax1) * (ay2 - ay1)
        area2 = (bx2 - bx1) * (by2 - by1)
        
        # Check if the rectangles overlap
        if ax2 <= bx1 or ax1 >= bx2 or ay2 <= by1 or ay1 >= by2:
            return area1 + area2
        
        # Calculate the overlapping area
        overlap_x = min(ax2, bx2) - max(ax1, bx1)
        overlap_y = min(ay2, by2) - max(ay1, by1)
        
        return area1 + area2 - overlap_x * overlap_y
        