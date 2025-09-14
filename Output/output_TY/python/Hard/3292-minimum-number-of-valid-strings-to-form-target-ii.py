# You are given an array of strings words and a string target.
# A string x is called valid if x is a prefix of any string in words.
# Return the minimum number of valid strings that can be concatenated to form target. If it is not possible to form target, return -1.
# Example 1:
# Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"
# Output: 3
# Explanation:
# The target string can be formed by concatenating:
# Prefix of length 2 of words[1], i.e. "aa".
# Prefix of length 3 of words[2], i.e. "bcd".
# Prefix of length 3 of words[0], i.e. "abc".
# Example 2:
# Input: words = ["abababab","ab"], target = "ababaababa"
# Output: 2
# Explanation:
# The target string can be formed by concatenating:
# Prefix of length 5 of words[0], i.e. "ababa".
# Prefix of length 5 of words[0], i.e. "ababa".
# Example 3:
# Input: words = ["abcdef"], target = "xyz"
# Output: -1
# Constraints:
# 1 <= words.length <= 100
# 1 <= words[i].length <= 5 * 104
# The input is generated such that sum(words[i].length) <= 105.
# words[i] consists only of lowercase English letters.
# 1 <= target.length <= 5 * 104
# target consists only of lowercase English letters.
class Solution(object):
    def minValidStrings(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        # Step 1: Build a set of all valid prefixes from words
        prefix_set = set()
        for word in words:
            for i in range(1, len(word) + 1):
                prefix = word[:i]
                prefix_set.add(prefix)

        n = len(target)
        dp = [float('inf')] * (n + 1)
        dp[0] = 0  # base case: empty string needs 0 strings

        for i in range(n):
            if dp[i] == float('inf'):
                continue
            # Try every possible prefix length starting at i
            for j in range(i + 1, n + 1):
                sub = target[i:j]
                if sub in prefix_set:
                    dp[j] = min(dp[j], dp[i] + 1)
                else:
                    break  # no longer a valid prefix, stop extending

        return -1 if dp[n] == float('inf') else dp[n]