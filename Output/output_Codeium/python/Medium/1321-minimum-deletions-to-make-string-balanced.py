#https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
#You are given a string s consisting only of characters 'a' and 'b'​​​​.
#You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
#Return the minimum number of deletions needed to make s balanced.
# 
#Example 1:
#Input: s = "aababbab"
#Output: 2
#Explanation: You can either:
#Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
#Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
#Example 2:
#Input: s = "bbaaaaabb"
#Output: 2
#Explanation: The only solution is to delete the first two characters.
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is 'a' or 'b'​​.
class Solution(object):
    def minimumDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [0] * (n + 1)
        for i in range(n):
            dp[i + 1] = dp[i] + (s[i] == 'b')
        res = dp[-1]
        for i in range(n):
            res = min(res, dp[i] + (n - i - 1) - (s[i] == 'a'))
        return res
