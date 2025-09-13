# You are given a string s and a pattern string p, where p contains exactly one '*' character.
# The '*' in p can be replaced with any sequence of zero or more characters.
# Return true if p can be made a substring of s, and false otherwise.
# Example 1:
# Input: s = "leetcode", p = "ee*e"
# Output: true
# Explanation:
# By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.
# Example 2:
# Input: s = "car", p = "c*v"
# Output: false
# Explanation:
# There is no substring matching the pattern.
# Example 3:
# Input: s = "luck", p = "u*"
# Output: true
# Explanation:
# The substrings "u", "uc", and "uck" match the pattern.
# Constraints:
# 1 <= s.length <= 50
# 1 <= p.length <= 50 
# s contains only lowercase English letters.
# p contains only lowercase English letters and exactly one '*'

class Solution(object):
    def hasMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if len(p) == 0:
            return len(s) == 0
        
        # If the pattern has a '*' at the end
        if p[-1] == '*':
            # If the substring before the '*' is matched by the pattern
            for i in range(len(s) + 1):
                if self.hasMatch(s[:i], p[:-2]):
                    return True
            
            # If the substring before the '*' is not matched by the pattern
            return self.hasMatch(s, p[:-2])
        
        # If the pattern does not have a '*' at the end
        return s[-1] == p[-1] and self.hasMatch(s[:-1], p[:-1]) 
        