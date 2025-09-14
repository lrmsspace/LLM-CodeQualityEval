#https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
#Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
#Return the maximum possible product of the lengths of the two palindromic subsequences.
#A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
# 
#Example 1:
#Input: s = "leetcodecom"
#Output: 9
#Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
#The product of their lengths is: 3 * 3 = 9.
#Example 2:
#Input: s = "bb"
#Output: 1
#Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
#The product of their lengths is: 1 * 1 = 1.
#Example 3:
#Input: s = "accbcaxxcxx"
#Output: 25
#Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
#The product of their lengths is: 5 * 5 = 25.
# 
#Constraints:
#	2 <= s.length <= 12
#	s consists of lowercase English letters only.
class Solution(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        # Fill the dp table for palindromic subsequences
        for i in range(n):
            dp[i][i] = 1     
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

        max_product = 0
        # Iterate through all pairs of non-overlapping subsequences
        for i in range(n):
            for j in range(i + 1, n):
                if dp[0][i] * dp[j][n - 1] > max_product:
                    max_product = dp[0][i] * dp[j][n - 1]
        return max_product   