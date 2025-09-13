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
        s_len = len(s)
        p_len = len(p)
        i = 0
        j = 0
        while i < s_len and j < p_len:
            if p[j] == '*':
                if j == p_len - 1:
                    return True
                while p[j+1] == '*':
                    j += 1
                if p[j+1] == s[i]:
                    i += 1
                    j += 1
                else:
                    i += 1
            else:
                if s[i] != p[j]:
                    return False
                i += 1
                j += 1
        return i == s_len and j == p_len
