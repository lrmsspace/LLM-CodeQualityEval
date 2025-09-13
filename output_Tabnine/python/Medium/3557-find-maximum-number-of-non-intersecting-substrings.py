# You are given a string word.
# Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
# Example 1:
# Input: word = "abcdeafdef"
# Output: 2
# Explanation:
# The two substrings are "abcdea" and "fdef".
# Example 2:
# Input: word = "bcdaaaab"
# Output: 1
# Explanation:
# The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
# Constraints:
# 1 <= word.length <= 2 * 105
# word consists only of lowercase English letters.

class Solution(object):
    def maxSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        n = len(word)
        dp = [0] * n
        res = 0
        
        for i in range(n):
            for j in range(i):
                if word[i] == word[j] and i - j >= 3:
                    dp[i] = max(dp[i], dp[j] + 1)
            res = max(res, dp[i])
        
        return res
        