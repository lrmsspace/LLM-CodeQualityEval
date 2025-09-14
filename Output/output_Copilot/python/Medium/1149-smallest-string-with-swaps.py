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
        # 1. 构建并查集
        parent = [i for i in range(len(s))] 
        rank = [1] * len(s)
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1
        # 2. 合并相连的节点
        for x, y in pairs:
            union(x, y)
        # 3. 将相连的节点进行排序
        from collections import defaultdict
        groups = defaultdict(list)
        for i in range(len(s)):
            groups[find(i)].append(i)
        # 4. 对每个组进行排序
        result = list(s)
        for indices in groups.values():
            chars = sorted([s[i] for i in indices])
            indices.sort()
            for i, char in zip(indices, chars):
                result[i] = char
        return ''.join(result)         