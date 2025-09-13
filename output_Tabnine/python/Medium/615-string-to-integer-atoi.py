#https://leetcode.com/problems/string-to-integer-atoi/
#Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
#The algorithm for myAtoi(string s) is as follows:
#	Whitespace: Ignore any leading whitespace (" ").
#	Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
#	Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
#	Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
#Return the integer as the final result.
# 
#Example 1:
#Input: s = "42"
#Output: 42
#Explanation:
#The underlined characters are what is read in and the caret is the current reader position.
#Step 1: "42" (no characters read because there is no leading whitespace)
#         ^
#Step 2: "42" (no characters read because there is neither a '-' nor '+')
#         ^
#Step 3: "42" ("42" is read in)
#           ^
#Example 2:
#Input: s = " -042"
#Output: -42
#Explanation:
#Step 1: "   -042" (leading whitespace is read and ignored)
#            ^
#Step 2: "   -042" ('-' is read, so the result should be negative)
#             ^
#Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
#               ^
#Example 3:
#Input: s = "1337c0d3"
#Output: 1337
#Explanation:
#Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
#         ^
#Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
#         ^
#Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
#             ^
#Example 4:
#Input: s = "0-1"
#Output: 0
#Explanation:
#Step 1: "0-1" (no characters read because there is no leading whitespace)
#         ^
#Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
#         ^
#Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
#          ^
#Example 5:
#Input: s = "words and 987"
#Output: 0
#Explanation:
#Reading stops at the first non-digit character 'w'.
# 
#Constraints:
#	0 <= s.length <= 200
#	s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize sign, integer, and flag for decimal point
        sign, num, decimal_flag = 1, 0, False
        
        # Skip leading whitespace
        i = 0
        while i < len(s) and s[i] =='':
            i += 1
        
        # Determine sign
        if i < len(s) and (s[i] == '+' or s[i] == '-'):
            sign = -1 if s[i] == '-' else 1
            i += 1
        
        # Read integer part
        while i < len(s) and s[i].isdigit():
            num = num * 10 + int(s[i])
            i += 1
            
            # Check if integer part exceeds the 32-bit signed integer range
            if num > 2**31 - 1 and sign == 1:
                return 2**31 - 1
            if num > 2**31 and sign == -1:
                return -2**31
        
        # Apply sign to integer part
        num *= sign
        
        # Check if decimal part exists
        if i < len(s) and s[i] == '.':
            i += 1
            decimal_flag = True
        
        # Read decimal part
        while i < len(s) and s[i].isdigit():
            num += int(s[i]) * 10**(-(i - decimal_pos))
            decimal_pos += 1
            i += 1
        
        # Round integer part to the nearest integer
        num = round(num)
        
        # Check if integer part exceeds the 32-bit signed integer range
        if num > 2**31 - 1 and sign == 1:
            return 2**31 - 1
        if num > 2**31 and sign == -1:
            return -2**31
        
        return int(num)
        