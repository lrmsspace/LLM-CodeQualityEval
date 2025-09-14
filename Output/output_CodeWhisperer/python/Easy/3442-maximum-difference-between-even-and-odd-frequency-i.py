# You are given a string s consisting of lowercase English letters.
# Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
# a1 has an odd frequency in the string.
# a2 has an even frequency in the string.
# Return this maximum difference.
# Example 1:
# Input: s = "aaaaabbc"
# Output: 3
# Explanation:
# The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
# The maximum difference is 5 - 2 = 3.
# Example 2:
# Input: s = "abcabcab"
# Output: 1
# Explanation:
# The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
# The maximum difference is 3 - 2 = 1.
# Constraints:
# 3 <= s.length <= 100
# s consists only of lowercase English letters.
# s contains at least one character with an odd frequency and one with an even frequency.

class Solution(object):
    def maxDifference(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_diff = -1
        for a1 in set(s):
            for a2 in set(s):
                if a1 != a2 and (s.count(a1) % 2 == 1 and s.count(a2) % 2 == 0):
                    diff = s.count(a1) - s.count(a2)
                    max_diff = max(max_diff, diff)
        return max_diff
                    