# You are given two positive integers, l and r. A positive integer is called beautiful if the product of its digits is divisible by the sum of its digits.
# Return the count of beautiful numbers between l and r, inclusive.
# Example 1:
# Input: l = 10, r = 20
# Output: 2
# Explanation:
# The beautiful numbers in the range are 10 and 20.
# Example 2:
# Input: l = 1, r = 15
# Output: 10
# Explanation:
# The beautiful numbers in the range are 1, 2, 3, 4, 5, 6, 7, 8, 9, and 10.
# Constraints:
# 1 <= l <= r < 109

class Solution(object):
    def beautifulNumbers(self, l, r):
        """
        :type l: int
        :type r: int
        :rtype: int
        """
        count = 0
        for num in range(l, r + 1):
            digits = [int(digit) for digit in str(num)]
            product = 1
            sum_digits = sum(digits)
            if sum_digits == 0:
                continue
            for digit in digits:
                product *= digit
            if product % sum_digits == 0:
                count += 1
        return count
        