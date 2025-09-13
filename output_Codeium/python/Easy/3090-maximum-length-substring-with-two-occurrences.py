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
        seen = {}
        start = 0
        max_len = 0
        for i, c in enumerate(s):
            if c in seen:
                start = max(start, seen[c] + 1)
            seen[c] = i
            max_len = max(max_len, i - start + 1)
        return max_len
