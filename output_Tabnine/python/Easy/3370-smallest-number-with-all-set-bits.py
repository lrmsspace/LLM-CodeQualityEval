# You are given a positive number n.
# Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits
# Example 1:
# Input: n = 5
# Output: 7
# Explanation:
# The binary representation of 7 is "111".
# Example 2:
# Input: n = 10
# Output: 15
# Explanation:
# The binary representation of 15 is "1111".
# Example 3:
# Input: n = 3
# Output: 3
# Explanation:
# The binary representation of 3 is "11".
# Constraints:
# 1 <= n <= 1000

class Solution(object):
    def smallestNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize the smallest number with n
        x = n
        
        # While the number of set bits in x is less than the number of set bits in n
        while bin(x).count('1') < bin(n).count('1'):
            x += 1
        
        return x
        