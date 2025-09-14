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
        if len(points) < 3:
            return len(points)
        
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        
        def get_slope(p1, p2):
            dy = p2[1] - p1[1]
            dx = p2[0] - p1[0]
            if dx == 0:
                return (1, 0)    

            if dy == 0:
                return (0, 1)

            g = gcd(dy, dx)
            return (dy // g, dx // g) if dx > 0 else (-dy // g, -dx // g)

        max_points = 0
        for i in range(len(points)):
            slopes = {}
            for j in range(len(points)):
                if i != j:
                    slope = get_slope(points[i], points[j])
                    slopes[slope] = slopes.get(slope, 0) + 1
            max_points = max(max_points, max(slopes.values(), default=0) + 1)
        return max_points    