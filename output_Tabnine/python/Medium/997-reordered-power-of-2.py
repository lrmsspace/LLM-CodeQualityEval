#https://leetcode.com/problems/reordered-power-of-2/
#You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
#Return true if and only if we can do this so that the resulting number is a power of two.
# 
#Example 1:
#Input: n = 1
#Output: true
#Example 2:
#Input: n = 10
#Output: false
# 
#Constraints:
#	1 <= n <= 109
class Solution(object):
    def reorderedPowerOf2(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # Convert n to a string and sort the digits
        sorted_n = ''.join(sorted(str(n)))
        
        # Check if the sorted digits form a power of 2
        for i in range(31):
            power_of_2 = 1 << i
            if ''.join(sorted(str(power_of_2))) == sorted_n:
                return True
        
        return False
        