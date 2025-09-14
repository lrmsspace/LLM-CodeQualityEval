#https://leetcode.com/problems/valid-number/
#Given a string s, return whether s is a valid number.
#For example, all the following are valid numbers: "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", while the following are not valid numbers: "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53".
#Formally, a valid number is defined using one of the following definitions:
#	An integer number followed by an optional exponent.
#	A decimal number followed by an optional exponent.
#An integer number is defined with an optional sign '-' or '+' followed by digits.
#A decimal number is defined with an optional sign '-' or '+' followed by one of the following definitions:
#	Digits followed by a dot '.'.
#	Digits followed by a dot '.' followed by digits.
#	A dot '.' followed by digits.
#An exponent is defined with an exponent notation 'e' or 'E' followed by an integer number.
#The digits are defined as one or more digits.
# 
#Example 1:
#Input: s = "0"
#Output: true
#Example 2:
#Input: s = "e"
#Output: false
#Example 3:
#Input: s = "."
#Output: false
# 
#Constraints:
#	1 <= s.length <= 20
#	s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def skip_spaces(s):
            i = 0
            while i < len(s) and s[i] =='':
                i += 1
            return i
        
        def is_digit(s, i):
            return '0' <= s[i] <= '9'
        
        def is_decimal(s, i):
            if i < len(s) and s[i] == '.':
                i += 1
                return is_digit(s, i)
            return False
        
        def is_exponential(s, i):
            if i < len(s) and (s[i] == 'e' or s[i] == 'E'):
                i += 1
                return is_digit(s, i) or (s[i] == '+' or s[i] == '-') and is_digit(s, i + 1)
            return False
        
        i = skip_spaces(s)
        if i == len(s):
            return False
        
        if s[i] == '+' or s[i] == '-':
            i += 1
        
        if is_digit(s, i):
            i += 1
            if is_decimal(s, i) or is_exponential(s, i):
                return True
        
        if is_decimal(s, i):
            i += 1
            if is_exponential(s, i):
                return True
        
        return False

        