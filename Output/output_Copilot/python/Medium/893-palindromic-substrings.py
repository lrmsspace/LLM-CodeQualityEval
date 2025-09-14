#https://leetcode.com/problems/palindromic-substrings/
#Given a string s, return the number of palindromic substrings in it.
#A string is a palindrome when it reads the same backward as forward.
#A substring is a contiguous sequence of characters within the string.
# 
#Example 1:
#Input: s = "abc"
#Output: 3
#Explanation: Three palindromic strings: "a", "b", "c".
#Example 2:
#Input: s = "aaa"
#Output: 6
#Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists of lowercase English letters.
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        count = 0
        
        for i in range(n):
            dp[i][i] = 1
            count += 1
        
        for length in range(2, n + 1):
            for start in range(n - length + 1):
                end = start + length - 1
                if s[start] == s[end]:
                    if length == 2 or dp[start + 1][end - 1]:
                        dp[start][end] = 1
                        count += 1
        
        return count        