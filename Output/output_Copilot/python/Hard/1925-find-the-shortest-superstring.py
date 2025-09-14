#https://leetcode.com/problems/find-the-shortest-superstring/
#Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
#You may assume that no string in words is a substring of another string in words.
# 
#Example 1:
#Input: words = ["alex","loves","leetcode"]
#Output: "alexlovesleetcode"
#Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
#Example 2:
#Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
#Output: "gctaagttcatgcatc"
# 
#Constraints:
#	1 <= words.length <= 12
#	1 <= words[i].length <= 20
#	words[i] consists of lowercase English letters.
#	All the strings of words are unique.
class Solution(object):
    def shortestSuperstring(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        def overlap(a, b):
            max_overlap = 0
            for i in range(1, min(len(a), len(b)) + 1):
                if a[-i:] == b[:i]:
                    max_overlap = i
            return max_overlap

        n = len(words)
        dp = [[0] * n for _ in range(1 << n)]
        for i in range(n):
            for j in range(n):
                if i != j:
                    dp[1 << i][j] = overlap(words[i], words[j])

        for mask in range(1 << n):
            for i in range(n):
                if mask & (1 << i) == 0:
                    continue
                for j in range(n):
                    if mask & (1 << j) != 0 or i == j:
                        continue
                    new_mask = mask | (1 << j)
                    dp[new_mask][j] = max(dp[new_mask][j], dp[mask][i] + overlap(words[i], words[j]))

        max_len = 0
        last_word = -1
        for i in range(n):
            if dp[(1 << n) - 1][i] > max_len:
                max_len = dp[(1 << n) - 1][i]
                last_word = i

        superstring = ""
        mask = (1 << n) - 1
        while mask > 0:
            superstring += words[last_word][:len(words[last_word]) - max_len]
            mask ^= (1 << last_word)
            next_word = -1
            for i in range(n):
                if mask & (1 << i) == 0 and dp[mask][i] + overlap(words[last_word], words[i]) == max_len:
                    next_word = i
                    break
            last_word = next_word

        return superstring + words[last_word]        