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
        overlaps = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i != j:
                    for k in range(min(len(words[i]), len(words[j]))):
                        if words[i].endswith(words[j][:k]):
                            overlaps[i][j] = k
        
        dp = [[0] * n for _ in range(1 << n)]
        path = [[0] * n for _ in range(1 << n)]
        for mask in range(1, 1 << n):
            for bit in range(n):
                if (mask >> bit) & 1:
                    pmask = mask ^ (1 << bit)
                    if pmask == 0: continue
                    for i in range(n):
                        if (pmask >> i) & 1:
                            val = dp[pmask][i] + overlaps[i][bit]
                            if val > dp[mask][bit]:
                                dp[mask][bit] = val
                                path[mask][bit] = i
        
        perm = []
        i = (1 << n) - 1
        mask = max(enumerate(dp[-1]), key=lambda x: x[1])[0]
        while i > 0:
            perm.append(mask)
            mask ^= (1 << mask)
            mask = path[i][mask]
            i &= i - 1
        
        perm.reverse()
        res = words[perm[0]]
        for i in range(1, len(perm)):
            w = words[perm[i]]
            res += w[overlaps[perm[i-1]][perm[i]]:]
        return res
        