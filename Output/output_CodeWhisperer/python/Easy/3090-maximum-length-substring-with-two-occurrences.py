# Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
# Example 1:
# Input: s = "bcbbbcba"
# Output: 4
# Explanation:
# The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
# Example 2:
# Input: s = "aaaa"
# Output: 2
# Explanation:
# The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
# Constraints:
# 2 <= s.length <= 100
# s consists only of lowercase English letters.

class Solution(object):
    def maximumLengthSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_length = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                substring = s[i:j+1]
                if len(set(substring)) <= 2 and len(substring) > max_length:
                    max_length = len(substring)
        return max_length        