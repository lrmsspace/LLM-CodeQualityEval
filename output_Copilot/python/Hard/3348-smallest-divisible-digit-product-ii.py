# You are given a string num which represents a positive integer, and an integer t.
# A number is called zero-free if none of its digits are 0.
# Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
# Example 1:
# Input: num = "1234", t = 256
# Output: "1488"
# Explanation:
# The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
# Example 2:
# Input: num = "12355", t = 50
# Output: "12355"
# Explanation:
# 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.
# Example 3:
# Input: num = "11111", t = 26
# Output: "-1"
# Explanation:
# No number greater than 11111 has the product of its digits divisible by 26.
# Constraints:
# 2 <= num.length <= 2 * 105
# num consists only of digits in the range ['0', '9'].
# num does not contain leading zeros.
# 1 <= t <= 1014

class Solution(object):
    def smallestNumber(self, num, t):
        """
        :type num: str
        :type t: int
        :rtype: str
        """
        from math import gcd
        from functools import reduce

        # Function to calculate the product of digits in a string
        def product_of_digits(s):
            prod = 1
            for char in s:
                prod *= int(char)
            return prod

        # Check if the number is zero-free
        if '0' in num:
            return "-1"

        # Calculate the product of digits in num
        current_product = product_of_digits(num)

        # If the current product is already divisible by t, return num
        if current_product % t == 0:
            return num

        # Find the smallest zero-free number greater than or equal to num
        n = len(num)
        for i in range(n):
            for digit in range(int(num[i]) + 1, 10):
                new_num = num[:i] + str(digit) + '1' * (n - i - 1)
                if '0' not in new_num and product_of_digits(new_num) % t == 0:
                    return new_num

        return "-1"
        