#https://leetcode.com/problems/super-palindromes/
#Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
#Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].
# 
#Example 1:
#Input: left = "4", right = "1000"
#Output: 4
#Explanation: 4, 9, 121, and 484 are superpalindromes.
#Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
#Example 2:
#Input: left = "1", right = "2"
#Output: 1
# 
#Constraints:
#	1 <= left.length, right.length <= 18
#	left and right consist of only digits.
#	left and right cannot have leading zeros.
#	left and right represent integers in the range [1, 1018 - 1].
#	left is less than or equal to right.
class Solution(object):
    def superpalindromesInRange(self, left, right):
        """
        :type left: str
        :type right: str
        :rtype: int
        """
        # Function to check if a number is a palindrome
        def is_palindrome(n):
            return str(n) == str(n)[::-1]
        
        # Function to check if a number is a super-palindrome
        def is_super_palindrome(n):
            return is_palindrome(n) and is_palindrome(n * n)
        
        # Convert strings to integers
        left, right = int(left), int(right)
        
        # Initialize count
        count = 0
        
        # Iterate over the range of numbers
        for num in range(left, right + 1):
            # Check if the number is a super-palindrome
            if is_super_palindrome(num):
                count += 1
        
        return count
        