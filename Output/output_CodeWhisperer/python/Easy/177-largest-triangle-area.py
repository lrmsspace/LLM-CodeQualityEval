#https://leetcode.com/problems/largest-triangle-area/
#Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.
# 
#Example 1:
#Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
#Output: 2.00000
#Explanation: The five points are shown in the above figure. The red triangle is the largest.
#Example 2:
#Input: points = [[1,0],[0,0],[0,1]]
#Output: 0.50000
# 
#Constraints:
#	3 <= points.length <= 50
#	-50 <= xi, yi <= 50
#	All the given points are unique.
class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        max_area = 0
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                for k in range(j+1, len(points)):
                    area = abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1])) / 2.0
                    max_area = max(max_area, area)
        return max_area 
        
