#https://leetcode.com/problems/check-if-point-is-reachable/
#There exists an infinitely large grid. You are currently at point (1, 1), and you need to reach the point (targetX, targetY) using a finite number of steps.
#In one step, you can move from point (x, y) to any one of the following points:
#	(x, y - x)
#	(x - y, y)
#	(2 * x, y)
#	(x, 2 * y)
#Given two integers targetX and targetY representing the X-coordinate and Y-coordinate of your final position, return true if you can reach the point from (1, 1) using some number of steps, and false otherwise.
# 
#Example 1:
#Input: targetX = 6, targetY = 9
#Output: false
#Explanation: It is impossible to reach (6,9) from (1,1) using any sequence of moves, so false is returned.
#Example 2:
#Input: targetX = 4, targetY = 7
#Output: true
#Explanation: You can follow the path (1,1) -> (1,2) -> (1,4) -> (1,8) -> (1,7) -> (2,7) -> (4,7).
# 
#Constraints:
#	1 <= targetX, targetY <= 109
class Solution(object):
    def isReachable(self, targetX, targetY):
        """
        :type targetX: int
        :type targetY: int
        :rtype: bool
        """
        def is_reachable(x, y):
            if x == targetX and y == targetY:
                return True
            if x <= 0 or y <= 0:
                return False
            if x + y <= min(targetX, targetY):
                return is_reachable(x, y - x) or is_reachable(x - y, y) or is_reachable(2 * x, y) or is_reachable(x, 2 * y)
            return False
        
        return is_reachable(1, 1)
        