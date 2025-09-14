#https://leetcode.com/problems/minimum-area-rectangle-ii/
#You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
#Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
#Answers within 10-5 of the actual answer will be accepted.
# 
#Example 1:
#Input: points = [[1,2],[2,1],[1,0],[0,1]]
#Output: 2.00000
#Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
#Example 2:
#Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
#Output: 1.00000
#Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
#Example 3:
#Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
#Output: 0
#Explanation: There is no possible rectangle to form from these points.
# 
#Constraints:
#	1 <= points.length <= 50
#	points[i].length == 2
#	0 <= xi, yi <= 4 * 104
#	All the given points are unique.
class Solution(object):
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        
        def distance(p1, p2):
            return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
        
        def cross(p1, p2, p3):
            return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])
        
        points = set(map(tuple, points))
        ans = float('inf')
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                p1, p2 = points[i], points[j]
                for k in range(j + 1, len(points)):
                    p3 = points[k]
                    if cross(p1, p2, p3) == 0:
                        d = distance(p1, p2) * distance(p2, p3) * distance(p3, p1)
                        ans = min(ans, d)
        return 0 if ans == float('inf') else ans ** 0.5
