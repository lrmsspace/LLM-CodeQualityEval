#https://leetcode.com/problems/smallest-string-with-swaps/
#You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
#You can swap the characters at any pair of indices in the given pairs any number of times.
#Return the lexicographically smallest string that s can be changed to after using the swaps.
# 
#Example 1:
#Input: s = "dcab", pairs = [[0,3],[1,2]]
#Output: "bacd"
#Explaination: 
#Swap s[0] and s[3], s = "bcad"
#Swap s[1] and s[2], s = "bacd"
#Example 2:
#Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
#Output: "abcd"
#Explaination: 
#Swap s[0] and s[3], s = "bcad"
#Swap s[0] and s[2], s = "acbd"
#Swap s[1] and s[2], s = "abcd"
#Example 3:
#Input: s = "cba", pairs = [[0,1],[1,2]]
#Output: "abc"
#Explaination: 
#Swap s[0] and s[1], s = "bca"
#Swap s[1] and s[2], s = "bac"
#Swap s[0] and s[1], s = "abc"
# 
#Constraints:
#	1 <= s.length <= 10^5
#	0 <= pairs.length <= 10^5
#	0 <= pairs[i][0], pairs[i][1] < s.length
#	s only contains lower case English letters.
class Solution(object):
    def smallestStringWithSwaps(self, s, pairs):
        """
        :type s: str
        :type pairs: List[List[int]]
        :rtype: str
        """
        n = len(s)
        f = list(range(n))
        def find(x):
            if f[x] != x:
                f[x] = find(f[x])
            return f[x]
        for x, y in pairs:
            f[find(x)] = find(y)
        d = {}
        for i in range(n):
            f[i] = find(i)
            if f[i] not in d:
                d[f[i]] = []
            d[f[i]].append(s[i])
        for k in d:
            d[k].sort()
        ans = []
        for i in range(n):
            ans.append(d[f[i]].pop(0))
        return ''.join(ans)
