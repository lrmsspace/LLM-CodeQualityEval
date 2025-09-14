#https://leetcode.com/problems/distinct-subsequences-ii/
#Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
#A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
# 
#Example 1:
#Input: s = "abc"
#Output: 7
#Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
#Example 2:
#Input: s = "aba"
#Output: 6
#Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
#Example 3:
#Input: s = "aaa"
#Output: 3
#Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
# 
#Constraints:
#	1 <= s.length <= 2000
#	s consists of lowercase English letters.
class Solution(object):
    def distinctSubseqII(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(s)
        dp = [1] * (n + 1)
        last = [0] * 26
        
        for i in range(1, n + 1):
            for j in range(i):
                if s[i - 1]!= s[j]:
                    dp[i] = (dp[i] + dp[j]) % MOD
                    if s[i - 1]!= s[j - 1]:
                        dp[i] = (dp[i] - last[ord(s[j - 1]) - ord('a')]) % MOD
                last[ord(s[i - 1]) - ord('a')] = dp[j]
        
        return dp[n]
        