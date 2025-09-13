# Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.
# Example 1:
# Input: s = "abacb", k = 2
# Output: 4
# Explanation:
# The valid substrings are:
# "aba" (character 'a' appears 2 times).
# "abac" (character 'a' appears 2 times).
# "abacb" (character 'a' appears 2 times).
# "bacb" (character 'b' appears 2 times).
# Example 2:
# Input: s = "abcde", k = 1
# Output: 15
# Explanation:
# All substrings are valid because every character appears at least once.
# Constraints:
# 1 <= s.length <= 3000
# 1 <= k <= s.length
# s consists only of lowercase English letters.

class Solution(object):
    def numberOfSubstrings(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """

        count = 0
        freq = {}
        left = 0
        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1
            while len(freq) > k:
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    del freq[s[left]]
                left += 1
            count += right - left + 1
        return count
