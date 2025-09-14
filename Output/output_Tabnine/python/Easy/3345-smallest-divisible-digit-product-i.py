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
        # Convert the number to a string to iterate over its digits
        num_str = str(n)
        
        # Iterate over the digits of the number
        for i in range(len(num_str)):
            digit = int(num_str[i])
            
            # Check if the digit product is divisible by t
            if digit * int(num_str[:i] + num_str[i+1:]) % t == 0:
                # If it is, return the number
                return n
        
        # If no such number exists, return the next smallest number greater than n
        return n + 1
        