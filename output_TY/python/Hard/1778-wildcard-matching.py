#https://leetcode.com/problems/wildcard-matching/
#Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
#	'?' Matches any single character.
#	'*' Matches any sequence of characters (including the empty sequence).
#The matching should cover the entire input string (not partial).
# 
#Example 1:
#Input: s = "aa", p = "a"
#Output: false
#Explanation: "a" does not match the entire string "aa".
#Example 2:
#Input: s = "aa", p = "*"
#Output: true
#Explanation: '*' matches any sequence.
#Example 3:
#Input: s = "cb", p = "?a"
#Output: false
#Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
# 
#Constraints:
#	0 <= s.length, p.length <= 2000
#	s contains only lowercase English letters.
#	p contains only lowercase English letters, '?' or '*'.
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p: return not s
        first_match = bool(s) and p[0] in {s[0], '?'}
        if len(p) >= 2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or first_match and self.isMatch(s[1:], p)
        else:
            return first_match and self.isMatch(s[1:], p[1:])
        return False