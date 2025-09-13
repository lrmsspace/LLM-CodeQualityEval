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
        dp = [0] * n
        for i in range(n):
            dp[i] = i
            if self.isPalindrome(s[:i+1]):
                dp[i] = 0
                continue
            for j in range(i):
                if self.isPalindrome(s[j+1:i+1]):
                    dp[i] = min(dp[i], dp[j] + 1)
        return dp[n-1]
        