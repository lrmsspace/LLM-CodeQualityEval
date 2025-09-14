#https://leetcode.com/problems/palindrome-partitioning/
#Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
# 
#Example 1:
#Input: s = "aab"
#Output: [["a","a","b"],["aa","b"]]
#Example 2:
#Input: s = "a"
#Output: [["a"]]
# 
#Constraints:
#	1 <= s.length <= 16
#	s contains only lowercase English letters.
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        n = len(s)
        dp = [[] for _ in range(n)]
        for i in range(n):
            for j in range(i+1):
                if s[i] == s[j] and (i-j<2 or s[i-1]==s[j+1]):
                    dp[i].append(j)
        res = []
        def dfs(i, path):
            if i == n:
                res.append(path)
                return
            for j in dp[i]:
                dfs(j+1, path+[s[j:i+1]])
        dfs(0, [])
        return res