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
        # 1. 哈希表法
        # 2. 时间复杂度O(n^2)，空间复杂度O(n)
        point_set = set(map(tuple, points))
        min_area = float('inf')
        
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                if points[i][0] != points[j][0] and points[i][1] != points[j][1]:
                    if (points[i][0], points[j][1]) in point_set and (points[j][0], points[i][1]) in point_set:
                        area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1])
                        min_area = min(min_area, area)
        
        return min_area if min_area != float('inf') else 0   