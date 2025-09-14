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
        # Initialize a dp array and a palindrome check array
        dp = [i for i in range(n+1)]
        palindrome = [[False for _ in range(n)] for _ in range(n)]
        
        # Fill the palindrome check array
        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                if s[i] == s[j] and (j-i <= 2 or palindrome[i+1][j-1]):
                    palindrome[i][j] = True
        
        # Fill the dp array
        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                if palindrome[i][j]:
                    dp[i] = min(dp[i], dp[j+1]+1)
        
        return dp[0] - 1 # Subtract 1 to get the number of cuts
        