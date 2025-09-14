#https://leetcode.com/problems/valid-parenthesis-string/
#Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
#The following rules define a valid string:
#	Any left parenthesis '(' must have a corresponding right parenthesis ')'.
#	Any right parenthesis ')' must have a corresponding left parenthesis '('.
#	Left parenthesis '(' must go before the corresponding right parenthesis ')'.
#	'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
# 
#Example 1:
#Input: s = "()"
#Output: true
#Example 2:
#Input: s = "(*)"
#Output: true
#Example 3:
#Input: s = "(*))"
#Output: true
# 
#Constraints:
#	1 <= s.length <= 100
#	s[i] is '(', ')' or '*'.
class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left = 0
        right = 0
        star = 0
        for i in range(len(s)):
            if s[i] == '(':
                left += 1
            elif s[i] == ')':
                right += 1
            else:
                star += 1
            if right > left + star:
                return False
        return left <= right + star and right <= left + star