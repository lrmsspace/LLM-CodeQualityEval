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
        for i in range(n):
            for j in range(n):
                if i != j:
                    for k in range(len(words[i])):
                        if words[i][k:] == words[j][:len(words[i]) - k]:
                            dp[1 << i][j] = len(words[i]) + len(words[j]) - k
                            break
        for i in range(1, 1 << n):
            for j in range(n):
                if i & (1 << j) == 0:
                    continue
                for k in range(n):
                    if i & (1 << k) == 0:
                        continue
                    if dp[i | (1 << k)][k] == 0 or dp[i][j] + dp[i][k] < dp[i | (1 << k)][k]:
                        dp[i | (1 << k)][k] = dp[i][j] + dp[i][k]
        ans = ''
        mask = (1 <<n) - 1
        for i in range(n):
            if dp[mask][i] + len(words[i]) < dp[mask][ans]:
                ans = i
        return words[ans] + words[ans][len(words[ans]) - dp[mask][ans]:]