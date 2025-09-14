#https://leetcode.com/problems/palindrome-partitioning-ii/
#Given a string s, partition s such that every substring of the partition is a palindrome.
#Return the minimum cuts needed for a palindrome partitioning of s.
# 
#Example 1:
#Input: s = "aab"
#Output: 1
#Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
#Example 2:
#Input: s = "a"
#Output: 0
#Example 3:
#Input: s = "ab"
#Output: 1
# 
#Constraints:
#	1 <= s.length <= 2000
#	s consists of lowercase English letters only.
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [i for i in range(n)]
        for i in range(n):
            j = 0
            while i-j >= 0 and i+j < n and s[i-j] == s[i+j]:
                dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1)
                j += 1
            j = 1
            while i-j+1 >= 0 and i+j < n and s[i-j+1] == s[i+j]:
                dp[i+j+1] = min(dp[i+j+1], dp[i-j+1]+1)
                j += 1
       return dp[n-1]