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
        
        ans = 1
        for i in range(len(darts)):
            for j in range(i+1, len(darts)):
                x1, y1 = darts[i]
                x2, y2 = darts[j]
                x3 = (x1+x2)/2
                y3 = (y1+y2)/2
                a = x1-x2
                b = y1-y2
                c = (x1*y2-x2*y1)/2
                d = r*r
                
                x4 = (a*d-b*c)/(a*a+b*b)
                y4 = (b*d-a*c)/(a*a+b*b)
                x5 = 2*x4-x3
                y5 = 2*y4-y3
                
                count = 0
                for x, y in darts:
                    if (x-x4)**2+(y-y4)**2 <= d or (x-x5)**2+(y-y5)**2 <= d:
                        count += 1
                ans = max(ans, count)
        return ans
