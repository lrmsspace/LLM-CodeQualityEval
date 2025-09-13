# You are given two strings, word1 and word2, of equal length. You need to transform word1 into word2.
# For this, divide word1 into one or more contiguous substrings. For each substring substr you can perform the following operations:
# Replace: Replace the character at any one index of substr with another lowercase English letter.
# Swap: Swap any two characters in substr.
# Reverse Substring: Reverse substr.
# Each of these counts as one operation and each character of each substring can be used in each type of operation at most once (i.e. no single index may be involved in more than one replace, one swap, or one reverse).
# Return the minimum number of operations required to transform word1 into word2.
# Example 1:
# Input: word1 = "abcdf", word2 = "dacbe"
# Output: 4
# Explanation:
# Divide word1 into "ab", "c", and "df". The operations are:
# For the substring "ab",
# Perform operation of type 3 on "ab" -> "ba".
# Perform operation of type 1 on "ba" -> "da".
# For the substring "c" do no operations.
# For the substring "df",
# Perform operation of type 1 on "df" -> "bf".
# Perform operation of type 1 on "bf" -> "be".
# Example 2:
# Input: word1 = "abceded", word2 = "baecfef"
# Output: 4
# Explanation:
# Divide word1 into "ab", "ce", and "ded". The operations are:
# For the substring "ab",
# Perform operation of type 2 on "ab" -> "ba".
# For the substring "ce",
# Perform operation of type 2 on "ce" -> "ec".
# For the substring "ded",
# Perform operation of type 1 on "ded" -> "fed".
# Perform operation of type 1 on "fed" -> "fef".
# Example 3:
# Input: word1 = "abcdef", word2 = "fedabc"
# Output: 2
# Explanation:
# Divide word1 into "abcdef". The operations are:
# For the substring "abcdef",
# Perform operation of type 3 on "abcdef" -> "fedcba".
# Perform operation of type 2 on "fedcba" -> "fedabc".
# Constraints:
# 1 <= word1.length == word2.length <= 100
# word1 and word2 consist only of lowercase English letters.

class Solution(object):
    def minOperations(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if word1 == word2:
            return 0
        
        n = len(word1)
        dp = [[float('inf')] * (n + 1) for _ in range(n + 1)]
        
        for i in range(n + 1):
            dp[i][0] = i
        for j in range(n + 1):
            dp[0][j] = j
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j] + 1,  # Delete
                                   dp[i][j - 1] + 1,  # Insert
                                   dp[i - 1][j - 1] + 1)
                    # Replace
                    if i > 1 and j > 1 and word1[i - 2] == word2[j - 1] and word1[i - 1] == word2[j - 2]:
                        dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + 1)
        return dp[n][n]
        