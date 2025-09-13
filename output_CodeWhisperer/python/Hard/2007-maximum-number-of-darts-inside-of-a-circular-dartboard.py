#https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/
#Alice is throwing n darts on a very large wall. You are given an array darts where darts[i] = [xi, yi] is the position of the ith dart that Alice threw on the wall.
#Bob knows the positions of the n darts on the wall. He wants to place a dartboard of radius r on the wall so that the maximum number of darts that Alice throws lie on the dartboard.
#Given the integer r, return the maximum number of darts that can lie on the dartboard.
# 
#Example 1:
#Input: darts = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
#Output: 4
#Explanation: Circle dartboard with center in (0,0) and radius = 2 contain all points.
#Example 2:
#Input: darts = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
#Output: 5
#Explanation: Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).
# 
#Constraints:
#	1 <= darts.length <= 100
#	darts[i].length == 2
#	-104 <= xi, yi <= 104
#	All the darts are unique
#	1 <= r <= 5000
class Solution(object):
    def numPoints(self, darts, r):
        """
        :type darts: List[List[int]]
        :type r: int
        :rtype: int
        """
        def is_inside(x, y, r, x0, y0):
            return (x - x0) ** 2 + (y - y0) ** 2 <= r ** 2
        n = len(darts)
        max_points = 1
        for i in range(n):
            x1, y1 = darts[i]
            for j in range(i + 1, n):
                x2, y2 = darts[j]
                x, y = (x1 + x2) / 2.0, (y1 + y2) / 2.0
                if (x1 - x2) ** 2 + (y1 - y2) ** 2 > 4 * r ** 2:
                    continue
                count = 0
                for x0, y0 in darts:
                    if is_inside(x, y, r, x0, y0):
                        count += 1
                max_points = max(max_points, count)
        return max_points
        