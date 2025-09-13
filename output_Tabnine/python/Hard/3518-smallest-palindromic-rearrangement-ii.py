# You are given a palindromic string s and an integer k.
# Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
# Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
# Example 1:
# Input: s = "abba", k = 2
# Output: "baab"
# Explanation:
# The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
# Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
# Example 2:
# Input: s = "aa", k = 2
# Output: ""
# Explanation:
# There is only one palindromic rearrangement: "aa".
# The output is an empty string since k = 2 exceeds the number of possible rearrangements.
# Example 3:
# Input: s = "bacab", k = 1
# Output: "abcba"
# Explanation:
# The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
# Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
# Constraints:
# 1 <= s.length <= 104
# s consists of lowercase English letters.
# s is guaranteed to be palindromic.
# 1 <= k <= 106

class Solution(object):
    def smallestPalindrome(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        # Convert the string to a list for easier manipulation
        chars = list(s)
        
        # Find the first character that is not in its correct position
        i = len(chars) - 1
        while i > 0 and chars[i] >= chars[i - 1]:
            i -= 1
        
        # If there is no such character, return an empty string
        if i == 0:
            return ""
        
        # Find the smallest character that should be in its correct position
        j = len(chars) - 1
        while chars[j] <= chars[i - 1]:
            j -= 1
        
        # Swap the characters
        chars[i - 1], chars[j] = chars[j], chars[i - 1]
        
        # Reverse the substring after the first character
        chars[i:] = chars[i:][::-1]
        
        # Convert the list back to a string
        result = "".join(chars)
        # If k is greater than the number of palindromic permutations, return an empty string
        if k > self.countPalindromes(s):
            return ""
        
        # Find the k-th lexicographically smallest palindromic permutation
        for _ in range(k - 1):
            result = self.nextPalindrome(result)
        
        return result
        