#https://leetcode.com/problems/valid-square/
#Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
#The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
#A valid square has four equal sides with positive length and four equal angles (90-degree angles).
# 
#Example 1:
#Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
#Output: true
#Example 2:
#Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
#Output: false
#Example 3:
#Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
#Output: true
# 
#Constraints:
#	p1.length == p2.length == p3.length == p4.length == 2
#	-104 <= xi, yi <= 104
class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        def distance(p1, p2):
            return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5
        
        side1 = distance(p1, p2)
        side2 = distance(p2, p3)
        side3 = distance(p3, p4)
        side4 = distance(p4, p1)
        
        if side1!= side2 or side2!= side3 or side3!= side4:
            return False
        
        angle1 = abs(math.degrees(math.atan2(p2[1] - p1[1], p2[0] - p1[0])))
        angle2 = abs(math.degrees(math.atan2(p3[1] - p2[1], p3[0] - p2[0])))
        angle3 = abs(math.degrees(math.atan2(p4[1] - p3[1], p4[0] - p3[0])))
        angle4 = abs(math.degrees(math.atan2(p1[1] - p4[1], p1[0] - p4[0])))
        
        return angle1 == 90 and angle2 == 90 and angle3 == 90 and angle4 == 90
        