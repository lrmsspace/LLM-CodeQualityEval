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
        parent = list(range(n))
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            parent[find(x)] = find(y)
        for x, y in pairs:
            union(x, y)
        groups = defaultdict(list)
        for i in range(n):
            groups[find(i)].append(i)
        res = list(s)
        for indices in groups.values():
            chars = sorted([s[i] for i in indices])
            for i, c in zip(sorted(indices), chars):
                res[i] = c
        return ''.join(res)
        