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
        n_str = str(n)
        
        # Reverse the string to facilitate grouping
        reversed_n_str = n_str[::-1]
        
        # Create a list to hold the parts of the new string
        parts = []
        
        # Iterate over the reversed string in chunks of 3 characters
        for i in range(0, len(reversed_n_str), 3):
            parts.append(reversed_n_str[i:i+3])
        
        # Join the parts with '.' and reverse back to original order
        result = '.'.join(parts)[::-1]
        
        return result        