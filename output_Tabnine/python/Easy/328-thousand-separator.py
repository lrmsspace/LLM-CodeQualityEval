#https://leetcode.com/problems/thousand-separator/
#Given an integer n, add a dot (".") as the thousands separator and return it in string format.
# 
#Example 1:
#Input: n = 987
#Output: "987"
#Example 2:
#Input: n = 1234
#Output: "1.234"
# 
#Constraints:
#	0 <= n <= 231 - 1
class Solution(object):
    def thousandSeparator(self, n):
        """
        :type n: int
        :rtype: str
        """
        # Convert the integer to a string
        str_n = str(n)
        
        # Reverse the string to get the digits in reverse order
        reversed_str_n = str_n[::-1]
        
        # Initialize an empty string to store the reversed number with the thousands separator
        result = ""
        
        # Iterate over the reversed string
        for i, digit in enumerate(reversed_str_n):
            # If the current digit is the first digit or the third digit after a dot, add a dot
            if i % 3 == 0 and i > 0:
                result += "."
            
            # Add the current digit to the result
            result += digit
        
        # Reverse the result to get the final string with the thousands separator
        return result[::-1]
        
