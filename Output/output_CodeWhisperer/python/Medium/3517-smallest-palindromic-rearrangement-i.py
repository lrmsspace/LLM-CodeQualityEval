# You are given a palindromic string s.
# Return the lexicographically smallest palindromic permutation of s.
# Example 1:
# Input: s = "z"
# Output: "z"
# Explanation:
# A string of only one character is already the lexicographically smallest palindrome.
# Example 2:
# Input: s = "babab"
# Output: "abbba"
# Explanation:
# Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
# Example 3:
# Input: s = "daccad"
# Output: "acddca"
# Explanation:
# Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
# Constraints:
# 1 <= s.length <= 105
# s consists of lowercase English letters.
# s is guaranteed to be palindromic.

class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        s = list(s)
        for i in range(n // 2):
            if s[i] != s[n - 1 - i]:
                min_char = min(s[i], s[n - 1 - i])
                s[i] = s[n - 1 - i] = min_char
        return "".join(s)        