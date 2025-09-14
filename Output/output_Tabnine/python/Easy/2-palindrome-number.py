#https://leetcode.com/problems/palindrome-number/
#Given an integer x, return true if x is a palindrome, and false otherwise.
# 
#Example 1:
#Input: x = 121
#Output: true
#Explanation: 121 reads as 121 from left to right and from right to left.
#Example 2:
#Input: x = -121
#Output: false
#Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
#Example 3:
#Input: x = 10
#Output: false
#Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
# 
#Constraints:
#	-231 <= x <= 231 - 1
# 
#Follow up: Could you solve it without converting the integer to a string?
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # If x is negative, it's not a palindrome
        if x < 0:
            return False
        
        # Initialize a variable to store the reversed number
        reversed_x = 0
        
        # While x is greater than 0
        while x > 0:
            # Get the last digit of x
            last_digit = x % 10
            
            # Add the last digit to the reversed number
            reversed_x = reversed_x * 10 + last_digit
            
            # Remove the last digit from x
            x = x // 10
        
        # Compare the original number with the reversed number
        return reversed_x == x
        