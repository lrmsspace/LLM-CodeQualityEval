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
        def distance(x1, y1, x2, y2):
            return (x1 - x2) ** 2 + (y1 - y2) ** 2

        def is_inside_circle(x, y, r):
            return x ** 2 + y ** 2 <= r ** 2

        n = len(darts)
        max_darts = 0

        for i in range(n):
            for j in range(i + 1, n):
                x1, y1 = darts[i]
                x2, y2 = darts[j]
                d = distance(x1, y1, x2, y2)

                if d > (r * 2) ** 2:
                    continue

                mid_x = (x1 + x2) / 2
                mid_y = (y1 + y2) / 2
                h = (r ** 2 - d / 4) ** 0.5

                center_x1 = mid_x + h * (y1 - y2) / d ** 0.5
                center_y1 = mid_y - h * (x1 - x2) / d ** 0.5
                center_x2 = mid_x - h * (y1 - y2) / d ** 0.5
                center_y2 = mid_y + h * (x1 - x2) / d ** 0.5

                count1 = sum(is_inside_circle(x - center_x1, y - center_y1, r) for x, y in darts)
                count2 = sum(is_inside_circle(x - center_x2, y - center_y2, r) for x, y in darts)

                max_darts = max(max_darts, count1, count2)

        return max_darts + 1 if max_darts else 0        