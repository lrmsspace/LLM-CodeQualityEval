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
        xy = set()
        for x, y in points:
            xy.add((x, y))
        ans = float('inf')
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                if x1 != x2 and y1 != y2 and (x1, y2) in xy and (x2, y1) in xy:
                    ans = min(ans, abs(x1-x2)*abs(y1-y2))
        return ans if ans != float('inf') else 0