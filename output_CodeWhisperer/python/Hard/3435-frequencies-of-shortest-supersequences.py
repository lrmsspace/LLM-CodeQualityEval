# You are given an array of strings words. Find all shortest common supersequences (SCS) of words that are not permutations of each other.
# A shortest common supersequence is a string of minimum length that contains each string in words as a subsequence.
# Return a 2D array of integers freqs that represent all the SCSs. Each freqs[i] is an array of size 26, representing the frequency of each letter in the lowercase English alphabet for a single SCS. You may return the frequency arrays in any order.
# Example 1:
# Input: words = ["ab","ba"]
# Output: [[1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
# Explanation:
# The two SCSs are "aba" and "bab". The output is the letter frequencies for each one.
# Example 2:
# Input: words = ["aa","ac"]
# Output: [[2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
# Explanation:
# The two SCSs are "aac" and "aca". Since they are permutations of each other, keep only "aac".
# Example 3:
# Input: words = ["aa","bb","cc"]
# Output: [[2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
# Explanation:
# "aabbcc" and all its permutations are SCSs.
# Constraints:
# 1 <= words.length <= 256
# words[i].length == 2
# All strings in words will altogether be composed of no more than 16 unique lowercase letters.
# All strings in words are unique.

class Solution(object):
    def supersequences(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def dfs(node, path):
            if len(path) > 1:
                count = 0
                for i in range(len(path) - 1):
                    diff = set(path[i + 1]).difference(set(path[i]))
                    count += len(diff)
                if count == len(path[-1]):
                    result.append(path.copy())

            for i in range(node, len(words)):
                path.append(words[i])
                dfs(i + 1, path)
                path.pop()

        result = []
        dfs(0, [])
        freqs = []
        for i in range(len(result)):
            freq = [0] * 26
            for j in range(len(result[i])):
                for k in range(len(result[i][j])):
                    freq[ord(result[i][j][k]) - ord('a')] += 1
            freqs.append(freq)
        return freqs
        