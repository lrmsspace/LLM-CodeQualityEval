# You are given two strings, s and t.
# You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
# Return the length of the longest palindrome that can be formed this way.
# Example 1:
# Input: s = "a", t = "a"
# Output: 2
# Explanation:
# Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
# Example 2:
# Input: s = "abc", t = "def"
# Output: 1
# Explanation:
# Since all characters are different, the longest palindrome is any single character, so the answer is 1.
# Example 3:
# Input: s = "b", t = "aaaa"
# Output: 4
# Explanation:
# Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
# Example 4:
# Input: s = "abcde", t = "ecdba"
# Output: 5
# Explanation:
# Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
# Constraints:
# 1 <= s.length, t.length <= 30
# s and t consist of lowercase English letters.

class Solution(object):
    def longestPalindrome(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        # Initialize two empty lists to store the palindromes
        palindromes_s = []
        palindromes_t = []
        
        # Iterate over the characters in s and t
        for i in range(len(s)):
            # Check if the substring starting at index i is a palindrome
            for j in range(i, len(s)):
                if s[i:j+1] == s[i:j+1][::-1]:
                    palindromes_s.append(s[i:j+1])
        
        for i in range(len(t)):
            # Check if the substring starting at index i is a palindrome
            for j in range(i, len(t)):
                if t[i:j+1] == t[i:j+1][::-1]:
                    palindromes_t.append(t[i:j+1])
        
        # Find the longest palindrome in palindromes_s and palindromes_t
        max_length = 0
        for palindrome in palindromes_s + palindromes_t:
            if len(palindrome) > max_length:
                max_length = len(palindrome)
        
        return max_length
        