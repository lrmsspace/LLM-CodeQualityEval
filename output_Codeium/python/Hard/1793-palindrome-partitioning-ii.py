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
        dp[0] = 0
        for i in xrange(1, n):
            if s[:i+1] == s[:i+1][::-1]:
                dp[i] = 0
            else:
                dp[i] = i
                for j in xrange(i):
                    if s[j:i+1] == s[j:i+1][::-1]:
                        dp[i] = min(dp[i], dp[j-1] + 1)
        return dp[-1]
