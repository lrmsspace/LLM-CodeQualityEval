#https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/
#You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
#Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
#Notes:
#	When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
#	Bob can remap a digit to itself, in which case num does not change.
#	Bob can remap different digits for obtaining minimum and maximum values respectively.
#	The resulting number after remapping can contain leading zeroes.
# 
#Example 1:
#Input: num = 11891
#Output: 99009
#Explanation: 
#To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
#To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
#The difference between these two numbers is 99009.
#Example 2:
#Input: num = 90
#Output: 99
#Explanation:
#The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
#Thus, we return 99.
# 
#Constraints:
#	1 <= num <= 108
class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        # Convert the number to a string for easier manipulation
        num_str = str(num)
        
        # Find the minimum and maximum values by replacing one digit
        min_val = num
        max_val = num
        for i in range(len(num_str)):
            for digit in range(10):
                new_num_str = num_str[:i] + str(digit) + num_str[i+1:]
                new_num = int(new_num_str)
                
                if digit < int(num_str[i]):
                    min_val = min(min_val, new_num)
                elif digit > int(num_str[i]):
                    max_val = max(max_val, new_num)
        
        return max_val - min_val
        