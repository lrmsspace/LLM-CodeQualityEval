# You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
# Example 1:
# Input: n = 10, t = 2
# Output: 10
# Explanation:
# The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
# Example 2:
# Input: n = 15, t = 3
# Output: 16
# Explanation:
# The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.
# Constraints:
# 1 <= n <= 100
# 1 <= t <= 10

class Solution(object):
    def smallestNumber(self, n, t):
        """
        :type n: int
        :type t: int
        :rtype: int
        """
        def digit_product(x):
            product = 1
            for digit in str(x):
                product *= int(digit)
            return product
        
        # Start checking from n and find the first number whose digit product is divisible by t
        while True:
            if digit_product(n) % t == 0:
                return n
            n += 1
