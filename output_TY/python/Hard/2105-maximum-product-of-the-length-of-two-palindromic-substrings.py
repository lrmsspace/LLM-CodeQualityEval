#https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/
#You are given a 0-indexed string s and are tasked with finding two non-intersecting palindromic substrings of odd length such that the product of their lengths is maximized.
#More formally, you want to choose four integers i, j, k, l such that 0 <= i <= j < k <= l < s.length and both the substrings s[i...j] and s[k...l] are palindromes and have odd lengths. s[i...j] denotes a substring from index i to index j inclusive.
#Return the maximum possible product of the lengths of the two non-intersecting palindromic substrings.
#A palindrome is a string that is the same forward and backward. A substring is a contiguous sequence of characters in a string.
# 
#Example 1:
#Input: s = "ababbb"
#Output: 9
#Explanation: Substrings "aba" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
#Example 2:
#Input: s = "zaaaxbbby"
#Output: 9
#Explanation: Substrings "aaa" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
# 
#Constraints:
#	2 <= s.length <= 105
#	s consists of lowercase English letters.
class Solution(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        mask = [0] * (1 << n)
        for i in range(n):
            for j in range(i, n):
                mask[1 << i | 1 << j] = s[i:j+1]
        palindromes = [s[i:j+1] for i in range(n) for j in range(i, n) if s[i:j+1] == s[i:j+1][::-1]]
        dp = [[0] * (1 << len(palindromes)) for _ in range(n + 1)]
        for i in range(n, -1, -1):
            for S in range(1 << len(palindromes)):
                for j in range(len(palindromes)):
                    if S & (1 << j):
                        continue
                    if mask[S | (1 << j)] == palindromes[j]:
                        dp[i][S] = max(dp[i][S], dp[i + len(palindromes[j])][S | (1 << j)] + len(palindromes[j]) * (n - i))
        return dp[0][0]