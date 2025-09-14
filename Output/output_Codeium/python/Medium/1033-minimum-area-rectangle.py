#https://leetcode.com/problems/minimum-area-rectangle/
#You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
#Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
# 
#Example 1:
#Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
#Output: 4
#Example 2:
#Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
#Output: 2
# 
#Constraints:
#	1 <= points.length <= 500
#	points[i].length == 2
#	0 <= xi, yi <= 4 * 104
#	All the given points are unique.
class Solution(object):
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        point_set = set()
        min_area = float('inf')
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                if points[i][0] == points[j][0]:
                    for k in range(len(points)):
                        if points[k][1] == points[i][1] and k != i and k != j:
                            for l in range(len(points)):
                                if points[l][1] == points[j][1] and l != i and l != j and l != k:
                                    min_area = min(min_area, abs(points[i][0] - points[l][0]) * abs(points[j][1] - points[k][1]))
                elif points[i][1] == points[j][1]:
                    for k in range(len(points)):
                        if points[k][0] == points[i][0] and k != i and k != j:
                            for l in range(len(points)):
                                if points[l][0] == points[j][0] and l != i and l != j and l != k:
                                    min_area = min(min_area, abs(points[i][1] - points[l][1]) * abs(points[j][0] - points[k][0]))
        return min_area if min_area != float('inf') else 0
