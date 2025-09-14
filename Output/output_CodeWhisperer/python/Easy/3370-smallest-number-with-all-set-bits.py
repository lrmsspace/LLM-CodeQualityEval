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
        if n == 1:
            return 1
        s = bin(n)[2:]
        if s.count('1') == 1:
            return n
        if s.count('0') == 0:
            return int('1' + '0' * (len(s) - 1), 2)
        if s[-1] == '1':
            return int(s, 2)
        i = s.rfind('1')
        return int(s[:i] + '1' + '0' * (len(s) - i - 1), 2)        