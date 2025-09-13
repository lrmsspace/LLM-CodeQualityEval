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
        n = len(points)
        if n < 3: return n
        ans = 0
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i+1, n):
                x2, y2 = points[j]
                if x1 == x2 and y1 == y2:
                    ans += 1
                else:
                    k = (y2 - y1) / (x2 - x1)
                    b = y1 - k * x1
                    cnt = 2
                    for p in points[j+1:]:
                        x3, y3 = p
                        if k * x3 + b == y3:
                            cnt += 1
                    ans = max(ans, cnt)
        return ans