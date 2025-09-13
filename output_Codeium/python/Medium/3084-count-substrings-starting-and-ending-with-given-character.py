# You are given a string s and a character c. Return the total number of substrings of s that start and end with c.
# Example 1:
# Input: s = "abada", c = "a"
# Output: 6
# Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".
# Example 2:
# Input: s = "zzz", c = "z"
# Output: 6
# Explanation: There are a total of 6 substrings in s and all start and end with "z".
# Constraints:
# 1 <= s.length <= 105
# s and c consist only of lowercase English letters.

class Solution(object):
    def countSubstrings(self, s, c):
        """
        :type s: str
        :type c: str
        :rtype: int
        """
        count = 0
        for i in range(len(s)):
            if s[i] == c:
                j = i + 1
                while j < len(s) and s[j] != c:
                    j += 1
                if j < len(s) and s[j] == c:
                    count += (j - i)
        return count

