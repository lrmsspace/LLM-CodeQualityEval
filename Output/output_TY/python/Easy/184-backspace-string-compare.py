#https://leetcode.com/problems/backspace-string-compare/
#Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
#Note that after backspacing an empty text, the text will continue empty.
# 
#Example 1:
#Input: s = "ab#c", t = "ad#c"
#Output: true
#Explanation: Both s and t become "ac".
#Example 2:
#Input: s = "ab##", t = "c#d#"
#Output: true
#Explanation: Both s and t become "".
#Example 3:
#Input: s = "a#c", t = "b"
#Output: false
#Explanation: s becomes "c" while t becomes "b".
# 
#Constraints:
#	1 <= s.length, t.length <= 200
#	s and t only contain lowercase letters and '#' characters.
# 
#Follow up: Can you solve it in O(n) time and O(1) space?
class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_stack = []
        t_stack = []
        for i in range(len(s)):
            if s[i]=='#':
                if len(s_stack)!=0:
                    s_stack.pop()
            else:
                s_stack.append(s[i])
        for i in range(len(t)):
            if t[i]=='#':
                if len(t_stack)!=0:
                    t_stack.pop()
            else:
                t_stack.append(t[i])
        return s_stack==t_stack