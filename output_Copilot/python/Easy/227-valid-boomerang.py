#https://leetcode.com/problems/valid-boomerang/
#Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.
#A boomerang is a set of three points that are all distinct and not in a straight line.
# 
#Example 1:
#Input: points = [[1,1],[2,3],[3,2]]
#Output: true
#Example 2:
#Input: points = [[1,1],[2,2],[3,3]]
#Output: false
# 
#Constraints:
#	points.length == 3
#	points[i].length == 2
#	0 <= xi, yi <= 100
class Solution(object):
    def isBoomerang(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        # Check if the points are distinct
        if len(points) != len(set(map(tuple, points))):
            return False
        
        # Check if the points are not in a straight line
        x1, y1 = points[0]
        x2, y2 = points[1]
        x3, y3 = points[2]
        
        # Calculate the area of the triangle formed by the three points
        area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))
        
        return area != 0        