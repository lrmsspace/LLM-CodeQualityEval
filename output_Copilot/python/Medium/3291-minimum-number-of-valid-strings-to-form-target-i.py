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
# 1 <= words[i].length <= 5 * 103
# The input is generated such that sum(words[i].length) <= 105.
# words[i] consists only of lowercase English letters.
# 1 <= target.length <= 5 * 103
# target consists only of lowercase English letters.

class Solution(object):
    def minValidStrings(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """

        # Create a set of valid prefixes from the words
        valid_prefixes = set()
        for word in words:
            for i in range(1, len(word) + 1):
                valid_prefixes.add(word[:i])

        # Try to form the target using the valid prefixes
        count = 0
        i = 0
        while i < len(target):
            found = False
            for j in range(i + 1, len(target) + 1):
                if target[i:j] in valid_prefixes:
                    found = True
                    count += 1
                    i = j
                    break
            if not found:
                return -1

        return count