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
from collections import Counter
import itertools
class Solution(object):
    def smallestPalindrome(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        
        # Count the frequency of each character
        char_count = Counter(s)
        half, middle = [], None

        # Check for more than one odd frequency character
        for char, count in char_count.items():
            if count % 2 == 1:
                if middle:
                    return ""  # More than one odd character count
                middle = char
            half.append(char * (count // 2))

        # Generate permutations of the half string
        half.sort()
        perms = sorted(set(itertools.permutations(half)))

        # Create palindromes from permutations
        palindromes = []
        for perm in perms:
            half_str = ''.join(perm)
            if middle:
                palindromes.append(half_str + middle + half_str[::-1])
            else:
                palindromes.append(half_str + half_str[::-1])

        # Find the kth smallest palindrome
        palindromes.sort()
        return palindromes[k - 1]