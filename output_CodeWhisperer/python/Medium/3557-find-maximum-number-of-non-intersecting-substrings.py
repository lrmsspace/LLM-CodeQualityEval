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

from collections import defaultdict
class Solution(object):
    def maxSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        n = len(word)
        dp = [0] * n
        count = defaultdict(int)
        for i in range(n):
            count[word[i]] += 1
            if count[word[i]] >= 4:
                dp[i] = 1
                for j in range(i):
                    if word[j] == word[i]:
                        dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)        