#https://leetcode.com/problems/max-points-on-a-line/
#Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
# 
#Example 1:
#Input: points = [[1,1],[2,2],[3,3]]
#Output: 3
#Example 2:
#Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
#Output: 4
# 
#Constraints:
#	1 <= points.length <= 300
#	points[i].length == 2
#	-104 <= xi, yi <= 104
#	All the points are unique.
class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        max_points = 0
        for i in range(len(points)):
            same_points = 1
            slope_dict = {}
            for j in range(i+1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                if x1 == x2 and y1 == y2:
                    same_points += 1
                elif x1 == x2:
                    slope = float('inf')
                else:
                    slope = (y2 - y1) / (x2 - x1)
                slope_dict[slope] = slope_dict.get(slope, 0) + 1
            max_points = max(max_points, same_points + max(slope_dict.values()))
        return max_points
        