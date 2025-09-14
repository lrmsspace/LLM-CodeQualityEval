#https://leetcode.com/problems/super-pow/
#Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
# 
#Example 1:
#Input: a = 2, b = [3]
#Output: 8
#Example 2:
#Input: a = 2, b = [1,0]
#Output: 1024
#Example 3:
#Input: a = 1, b = [4,3,3,8,5,2]
#Output: 1
# 
#Constraints:
#	1 <= a <= 231 - 1
#	1 <= b.length <= 2000
#	0 <= b[i] <= 9
#	b does not contain leading zeros.
class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        # Convert base to base 1337
        a = a % 1337
        
        # Initialize result
        res = 1
        
        # Iterate through each digit in b
        for digit in b:
            # Square the result and multiply by base
            res = (res * res) % 1337
            
            # Multiply result by digit
            res = (res * digit) % 1337
        
        return res
        