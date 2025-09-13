#https://leetcode.com/problems/monotone-increasing-digits/
#An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
#Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
# 
#Example 1:
#Input: n = 10
#Output: 9
#Example 2:
#Input: n = 1234
#Output: 1234
#Example 3:
#Input: n = 332
#Output: 299
# 
#Constraints:
#	0 <= n <= 109
class Solution(object):
    def monotoneIncreasingDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Convert the number to a string
        num_str = str(n)
        
        # Find the index of the first digit that decreases from its right
        i = len(num_str) - 2
        while i >= 0 and num_str[i] > num_str[i + 1]:
            i -= 1
        
        # If no digit decreases, return n
        if i == -1:
            return n
        
        # Find the largest digit that can be replaced without making the number smaller
        j = len(num_str) - 1
        while j > i and num_str[j] <= num_str[i]:
            j -= 1
        
        # Swap the digits
        num_str = list(num_str)
        num_str[i], num_str[j] = num_str[j], num_str[i]
        
        # Reverse the digits to the right of i
        num_str[i + 1:] = num_str[i + 1:][::-1]
        
        # Convert the string back to an integer
        return int(''.join(num_str))
        