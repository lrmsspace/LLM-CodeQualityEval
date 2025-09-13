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
        dp = [[0] * n for _ in range(n)]

        # Fill the dp table for palindromic substrings
        for i in range(n):
            dp[i][i] = 1   
        for length in range(3, n + 1, 2):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2 
                else:
                    dp[i][j] = 0

        max_product = 0
        for i in range(n):
            for j in range(i + 2, n):
                if dp[i][j] > 0:
                    for k in range(j + 2, n):
                        for l in range(k, n):
                            if dp[k][l] > 0:
                                max_product = max(max_product, dp[i][j] * dp[k][l])
        return max_product     