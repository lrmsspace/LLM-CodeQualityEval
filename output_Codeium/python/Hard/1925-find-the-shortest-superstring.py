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
        n = len(words)
        dp = [[0] * n for _ in range(1 << n)]
        for mask in range(1 << n):
            for i in range(n):
                if (mask >> i) & 1:
                    if not mask - (1 << i):
                        dp[mask][i] = len(words[i])
                    else:
                        for j in range(n):
                            if (mask >> j) & 1 and i != j:
                                dp[mask][i] = max(dp[mask][i], dp[mask - (1 << i)][j] + len(words[i] - words[j]))
        res = []
        mask = (1 << n) - 1
        i = 0
        while mask:
            if dp[mask][i] != dp[mask - (1 << i)][i]:
                res.append(words[i])
                mask -= 1 << i
                for j in range(n):
                    if j != i and dp[mask][j] > dp[mask - (1 << i)][i]:
                        i = j
                        break
            else:
                i = (i + 1) % n
        return ''.join(res[::-1])
