#https://leetcode.com/problems/palindrome-partitioning-iv/
#Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
#A string is said to be palindrome if it the same string when reversed.
# 
#Example 1:
#Input: s = "abcbdd"
#Output: true
#Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
#Example 2:
#Input: s = "bcbddxy"
#Output: false
#Explanation: s cannot be split into 3 palindromes.
# 
#Constraints:
#	3 <= s.length <= 2000
#	s​​​​​​ consists only of lowercase English letters.
class Solution(object):
    def checkPartitioning(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # dp[i][j] represents whether substring s[i:j+1] is a palindrome
        dp = [[False] * len(s) for _ in range(len(s))]
        
        # All substrings of length 1 are palindromes
        for i in range(len(s)):
            dp[i][i] = True
        
        # Check for palindromes of length 2 and longer
        for length in range(2, len(s) + 1):
            for i in range(len(s) - length + 1):
                j = i + length - 1
                if s[i] == s[j] and (length == 2 or dp[i + 1][j - 1]):
                    dp[i][j] = True
        
        # Check if there are three non-empty palindromic substrings
        for i in range(len(s)):
            for j in range(i + 2, len(s) + 1):
                if dp[i][j - 1] and dp[j][len(s) - 1]:
                    return True
        
        return False
        