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
        if not rectangles:
            return False
        if len(rectangles) == 1:
            return True
        x1, y1, x2, y2 = float('inf'), float('inf'), float('-inf'), float('-inf')
        area = 0
        points = set()
        for rect in rectangles:
            x1 = min(x1, rect[0])
            y1 = min(y1, rect[1])
            x2 = max(x2, rect[2])
            y2 = max(y2, rect[3])
            area += (rect[2] - rect[0]) * (rect[3] - rect[1])
            points.add((rect[0], rect[1]))
            points.add((rect[0], rect[3]))
            points.add((rect[2], rect[1]))
            points.add((rect[2], rect[3]))
        if (x2 - x1) * (y2 - y1) != area:
            return False
        points.remove((x1, y1))
        points.remove((x1, y2))
        points.remove((x2, y1))
        points.remove((x2, y2))
        return len(points) == 4 and all(points.count(p) == 2 for p in points)
        