#https://leetcode.com/problems/moving-stones-until-consecutive/
#There are three stones in different positions on the X-axis. You are given three integers a, b, and c, the positions of the stones.
#In one move, you pick up a stone at an endpoint (i.e., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints. Formally, let's say the stones are currently at positions x, y, and z with x < y < z. You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.
#The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
#Return an integer array answer of length 2 where:
#	answer[0] is the minimum number of moves you can play, and
#	answer[1] is the maximum number of moves you can play.
# 
#Example 1:
#Input: a = 1, b = 2, c = 5
#Output: [1,2]
#Explanation: Move the stone from 5 to 3, or move the stone from 5 to 4 to 3.
#Example 2:
#Input: a = 4, b = 3, c = 2
#Output: [0,0]
#Explanation: We cannot make any moves.
#Example 3:
#Input: a = 3, b = 5, c = 1
#Output: [1,2]
#Explanation: Move the stone from 1 to 4; or move the stone from 1 to 2 to 4.
# 
#Constraints:
#	1 <= a, b, c <= 100
#	a, b, and c have different values.
class Solution(object):
    def numMovesStones(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        # Sort the positions of the stones
        stones = sorted([a, b, c])
        min_moves = 0
        
        # Calculate the minimum moves needed to make the stones consecutive
        if stones[2] - stones[0] == 2:
            min_moves = 0
        elif stones[2] - stones[0] == 3 or stones[1] - stones[0] == 1 or stones[2] - stones[1] == 1:
            min_moves = 1
        else:
            min_moves = 2
                # Calculate the maximum moves needed to make the stones consecutive
            max_moves = (stones[1] - stones[0] - 1) + (stones[2] - stones[1] - 1)
                
        return [min_moves, max_moves]   