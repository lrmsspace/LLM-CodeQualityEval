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
        points_set = set(map(tuple, points))
        ans = float('inf')
        for i, (x1, y1) in enumerate(points):
            for j, (x2, y2) in enumerate(points[i:], i):
                if x1 < x2 and y1 < y2:
                    if (x1, y2) in points_set and (x2, y1) in points_set:
                        area = (x2 - x1) * (y2 - y1)
                        if area < ans:
                            ans = area
        return ans if ans < float('inf') else 0

        