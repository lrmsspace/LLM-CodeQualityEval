#https://leetcode.com/problems/numbers-with-repeated-digits/
#Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
# 
#Example 1:
#Input: n = 20
#Output: 1
#Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
#Example 2:
#Input: n = 100
#Output: 10
#Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
#Example 3:
#Input: n = 1000
#Output: 262
# 
#Constraints:
#	1 <= n <= 109
class Solution(object):
    def numDupDigitsAtMostN(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Count the number of digits in n
        num_digits = len(str(n))
        
        # Initialize variables
        num_with_repeated_digits = 0
        num_with_repeated_digits_excluding_last_digit = 10 ** (num_digits - 1) - 1
        
        # Iterate through each digit from right to left
        for i in range(num_digits - 1, -1, -1):
            digit = int(str(n)[i])
            
            # Calculate the number of valid digits for the current digit
            # If the current digit is the same as the previous digit, subtract the valid digits
            # from the number of valid digits excluding the last digit
            if i > 0 and str(n)[i] == str(n)[i - 1]:
                num_valid_digits = num_with_repeated_digits_excluding_last_digit
            else:
                num_valid_digits = num_with_repeated_digits_excluding_last_digit - num_with_repeated_digits_excluding_last_digit * (10 ** (num_digits - i - 1))
        
        # Calculate the number of valid digits for the first digit
        num_valid_digits_first_digit = n % (10 ** (num_digits - 1))
        
        # Add the valid digits for the first digit to the valid digits for the remaining digits
        num_with_repeated_digits += num_valid_digits_first_digit
        
        return n - num_with_repeated_digits
        