#https://leetcode.com/problems/closest-divisors/
#Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
#Return the two integers in any order.
# 
#Example 1:
#Input: num = 8
#Output: [3,3]
#Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
#Example 2:
#Input: num = 123
#Output: [5,25]
#Example 3:
#Input: num = 999
#Output: [40,25]
# 
#Constraints:
#	1 <= num <= 10^9
class Solution(object):
    def closestDivisors(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        # Find the closest divisor that, when multiplied by (num + 1), gives a perfect square
        def closest_square(n):
            root = int(n ** 0.5)
            return root * (root + 1)
        
        # Find the closest divisor that, when multiplied by (num + 2), gives a perfect square
        def closest_square_plus_one(n):
            root = int((n + 1) ** 0.5)
            return root * (root + 1)
        
        # Find the closest divisors
        closest_divisor_1 = closest_square(num) // (num + 1)
        closest_divisor_2 = closest_square_plus_one(num) // (num + 2)
        
        return [closest_divisor_1, closest_divisor_2]
        