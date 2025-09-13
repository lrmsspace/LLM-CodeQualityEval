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
        if targetX == 1 and targetY == 1:
            return True
        if targetX < targetY:
            targetX, targetY = targetY, targetX
        # 交换 x 和 y 的值，使得 x 始终大于等于 y
        while targetX > 1 and targetY > 1:
            if targetX % 2 == 0 and targetY % 2 == 0:
                # 如果 x 和 y 都是偶数，则可以将它们都除以 2
                targetX //= 2
                targetY //= 2
            elif targetX % 2 == 0:
                # 如果 x 是偶数，y 是奇数，则可以将 x 除以 2
                targetX //= 2
            elif targetY % 2 == 0:
                # 如果 x 是奇数，y 是偶数，则可以将 y 除以 2
                targetY //= 2
            else:
                # 如果 x 和 y 都是奇数，则无法继续操作，返回 False
                return False

        return True if (targetX == 1 or targetY == 1) else False        