#https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
#You are given two strings, word1 and word2. You want to construct a string in the following manner:
#	Choose some non-empty subsequence subsequence1 from word1.
#	Choose some non-empty subsequence subsequence2 from word2.
#	Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
#Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.
#A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.
#A palindrome is a string that reads the same forward as well as backward.
# 
#Example 1:
#Input: word1 = "cacb", word2 = "cbba"
#Output: 5
#Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.
#Example 2:
#Input: word1 = "ab", word2 = "ab"
#Output: 3
#Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.
#Example 3:
#Input: word1 = "aa", word2 = "bb"
#Output: 0
#Explanation: You cannot construct a palindrome from the described method, so return 0.
# 
#Constraints:
#	1 <= word1.length, word2.length <= 1000
#	word1 and word2 consist of lowercase English letters.
class Solution(object):
    def longestPalindrome(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        # Create a 2D array to store the lengths of longest common subsequences between word1[i:] and word2[j:]
        dp = [[0] * (len(word2) + 1) for _ in range(len(word1) + 1)]
        
        # Fill the dp array using the LCS algorithm
        for i in range(1, len(word1) + 1):
            for j in range(1, len(word2) + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        # Return the length of the longest palindrome that can be constructed
        return dp[-1][-1]
        