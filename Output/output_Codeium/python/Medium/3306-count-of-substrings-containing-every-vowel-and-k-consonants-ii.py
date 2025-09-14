# You are given a string word and a non-negative integer k.
# Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
# Example 1:
# Input: word = "aeioqq", k = 1
# Output: 0
# Explanation:
# There is no substring with every vowel.
# Example 2:
# Input: word = "aeiou", k = 0
# Output: 1
# Explanation:
# The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".
# Example 3:
# Input: word = "ieaouqqieaouqq", k = 1
# Output: 3
# Explanation:
# The substrings with every vowel and one consonant are:
# word[0..5], which is "ieaouq".
# word[6..11], which is "qieaou".
# word[7..12], which is "ieaouq".
# Constraints:
# 5 <= word.length <= 2 * 105
# word consists only of lowercase English letters.
# 0 <= k <= word.length - 5

class Solution(object):
    def countOfSubstrings(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        vowels = set('aeiou')
        dp = [[0]*(k+1) for _ in xrange(len(word)+1)]
        for i in xrange(1, len(word)+1):
            if word[i-1] in vowels:
                dp[i][0] = dp[i-1][0] + 1
            dp[i][0] += dp[i-1][0]
            for j in xrange(1, min(i, k+1)):
                if word[i-1] not in vowels:
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[-1][-1]
