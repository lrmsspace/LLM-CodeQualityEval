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
        s = s.strip()
        if len(s) == 0: return False
        if s[0] in ['+','-']: s = s[1:]
        if len(s) == 0: return False
        if s[0] not in ['0','1','2','3','4','5','6','7','8','9']: return False
        for i in range(len(s)):
            if s[i] in ['0','1','2','3','4','5','6','7','8','9']: continue
            if s[i] == '.':
                if i == 0 or i == len(s)-1: return False
                if s[i-1] not in ['0','1','2','3','4','5','6','7','8','9'] or s[i+1] not in ['0','1','2','3','4','5','6','7','8','9']: return False
                continue
            if s[i] in ['e','E']:
                if i == 0 or i == len(s)-1: return False
                if s[i-1] not in ['0','1','2','3','4','5','6','7','8','9'] or s[i+1] not in ['0','1','2','3','4','5','6','7','8','9']: return False
                continue
            return False
        return True