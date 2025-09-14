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
        area = 0
        x1, y1, x2, y2 = float('inf'), float('inf'), float('-inf'), float('-inf')
        points = set()
        for x, y, a, b in rectangles:
            area += (a - x) * (b - y)
            x1, y1, x2, y2 = min(x1, x), min(y1, y), max(x2, a), max(y2, b)
            for p in [(x, y), (x, b), (a, y), (a, b)]:
                if p in points:
                    points.remove(p)
                else:
                    points.add(p)
        return area == (x2 - x1) * (y2 - y1) and len(points) == 4 and (x1, y1) in points and (x2, y1) in points and (x1, y2) in points and (x2, y2) in points
