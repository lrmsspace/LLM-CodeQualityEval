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
        sPointer, tPointer = len(s) - 1, len(t) - 1
        sSkip, tSkip = 0, 0
        while sPointer >= 0 or tPointer >= 0:
            while sPointer >= 0:
                if s[sPointer] == '#':
                    sSkip += 1
                    sPointer -= 1
                elif sSkip > 0:
                    sSkip -= 1
                    sPointer -= 1
                else:
                    break
            while tPointer >= 0:
                if t[tPointer] == '#':
                    tSkip += 1
                    tPointer -= 1
                elif tSkip > 0:
                    tSkip -= 1
                    tPointer -= 1
                else:
                    break
            if sPointer >= 0 and tPointer >= 0 and s[sPointer] != t[tPointer]:
                return False
            if (sPointer >= 0) != (tPointer >= 0):
                return False
            sPointer -= 1
            tPointer -= 1
        return True
