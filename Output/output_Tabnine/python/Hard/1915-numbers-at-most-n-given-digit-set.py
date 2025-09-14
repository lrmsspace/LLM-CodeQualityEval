#https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
#Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
#Return the number of positive integers that can be generated that are less than or equal to a given integer n.
# 
#Example 1:
#Input: digits = ["1","3","5","7"], n = 100
#Output: 20
#Explanation: 
#The 20 numbers that can be written are:
#1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
#Example 2:
#Input: digits = ["1","4","9"], n = 1000000000
#Output: 29523
#Explanation: 
#We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
#81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
#2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
#In total, this is 29523 integers that can be written using the digits array.
#Example 3:
#Input: digits = ["7"], n = 8
#Output: 1
# 
#Constraints:
#	1 <= digits.length <= 9
#	digits[i].length == 1
#	digits[i] is a digit from '1' to '9'.
#	All the values in digits are unique.
#	digits is sorted in non-decreasing order.
#	1 <= n <= 109
class Solution(object):
    def atMostNGivenDigitSet(self, digits, n):
        """
        :type digits: List[str]
        :type n: int
        :rtype: int
        """
        # Convert n to string to facilitate manipulation
        n_str = str(n)
        
        # Count the number of digits in n
        n_digits = len(n_str)
        
        # Initialize the count of valid numbers
        count = 0
        
        # Iterate from 1 to the number of digits in n
        for i in range(1, n_digits + 1):
            # Calculate the number of digits that can be formed using the current digits
            # (i.e., the number of digits in n minus the current digit position)
            valid_digits = len(digits) ** (n_digits - i)
            
            # If the current digit is greater than the digit at position i in n
            # (i.e., the current digit is smaller than the digit at position i in n),
            # subtract the valid digits that can be formed using the remaining digits
            if i < n_digits and int(n_str[i-1]) > int(digits[0]):
                valid_digits -= len(digits) ** (n_digits - i - 1)
            
            # Add the valid digits to the count
            count += valid_digits
        
        # Add the number of valid digits that can be formed using the remaining digits
        # (i.e., the number of digits in n minus the number of digits considered so far)
        if n_digits > 1:
            count += len(digits) ** (n_digits - 1)
        
        return count
        