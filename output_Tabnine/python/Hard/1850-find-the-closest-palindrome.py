#https://leetcode.com/problems/find-the-closest-palindrome/
#Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
#The closest is defined as the absolute difference minimized between two integers.
# 
#Example 1:
#Input: n = "123"
#Output: "121"
#Example 2:
#Input: n = "1"
#Output: "0"
#Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
# 
#Constraints:
#	1 <= n.length <= 18
#	n consists of only digits.
#	n does not have leading zeros.
#	n is representing an integer in the range [1, 1018 - 1].
class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        # Convert n to an integer
        num = int(n)
        
        # Find the next palindrome by incrementing or decrementing num
        if num % 2 == 0:
            next_palindrome = str(num + 1) if num + 1 < 10 else str(num - 1)
        else:
            next_palindrome = str(num + 2) if num + 2 < 10 else str(num - 2)
        
        # Convert the next palindrome back to a string
        next_palindrome_str = next_palindrome
        
        # Calculate the absolute difference between num and the next palindrome
        diff = abs(num - int(next_palindrome_str))
        
        # Find the closest palindrome by comparing the absolute differences
        closest_palindrome = n if diff <= abs(num - int(n)) else next_palindrome_str
        
        return closest_palindrome
        