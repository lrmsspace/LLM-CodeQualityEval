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
        from collections import Counter
        from math import factorial

        # Count frequency of characters in s
        count = Counter(s)
        
        # Check if a palindromic arrangement is possible
        odd_count = sum(1 for v in count.values() if v % 2 != 0)
        if odd_count > 1:
            return ""
        # Prepare half of the palindrome
        half = []
        for char in sorted(count.keys()):
            half.append(char * (count[char] // 2))
        half = ''.join(half)
        # Generate all distinct palindromic permutations
        def generate_palindromes(half):
            if not half:
                return {""}
            palindromes = set()
            for i in range(len(half)):
                for perm in generate_palindromes(half[:i] + half[i+1:]):
                    palindromes.add(half[i] + perm + half[i])
            return palindromes
        palindromes = sorted(generate_palindromes(half))
        # Return the k-th smallest palindromic permutation
        if k <= len(palindromes):
            return palindromes[k - 1]
        else:
            return ""
        