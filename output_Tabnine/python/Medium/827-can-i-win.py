#https://leetcode.com/problems/can-i-win/
#In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
#What if we change the game so that players cannot re-use integers?
#For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
#Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.
# 
#Example 1:
#Input: maxChoosableInteger = 10, desiredTotal = 11
#Output: false
#Explanation:
#No matter which integer the first player choose, the first player will lose.
#The first player can choose an integer from 1 up to 10.
#If the first player choose 1, the second player can only choose integers from 2 up to 10.
#The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
#Same with other integers chosen by the first player, the second player will always win.
#Example 2:
#Input: maxChoosableInteger = 10, desiredTotal = 0
#Output: true
#Example 3:
#Input: maxChoosableInteger = 10, desiredTotal = 1
#Output: true
# 
#Constraints:
#	1 <= maxChoosableInteger <= 20
#	0 <= desiredTotal <= 300
class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        # Initialize memoization table
        memo = {}
        
        # Helper function to check if it's possible to reach the desired total
        def canReach(total, mask):
            # Check if the state has been computed before
            if (total, mask) in memo:
                return memo[(total, mask)]
            
            # If the total is greater than the desired total, it's impossible to reach
            if total >= desiredTotal:
                return False
            
            # If all integers have been chosen, it's possible to reach the desired total
            if mask == 0:
                return True
            
            # Iterate through all possible integers
            for i in range(1, maxChoosableInteger + 1):
                # If the current integer is not chosen
                if mask & (1 << i - 1) == 0:
                    # Check if it's possible to reach the desired total after choosing the current integer
                    if not canReach(total + i, mask ^ (1 << i - 1)):
                        memo[(total, mask)] = True
                        return True
            
            # If it's not possible to reach the desired total after choosing any integer
            memo[(total, mask)] = False
            return False
        
        # Check if it's possible to reach the desired total
        return canReach(0, (1 << maxChoosableInteger) - 1)
        