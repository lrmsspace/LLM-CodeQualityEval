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
        left, right = 0, n - 1
        
        while left < right:
            if s[left]!= s[right]:
                break
            left += 1
            right -= 1
        
        if left >= right:
            return s + s[::-1]
        
        for i in range(n - 1, left - 1, -1):
            if s[i] < s[right]:
                s = s[:i] + s[i+1:] + s[right]
                break
        
        return s + s[::-1]
        