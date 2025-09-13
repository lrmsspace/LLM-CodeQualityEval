#https://leetcode.com/problems/possible-bipartition/
#We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
#Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
# 
#Example 1:
#Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
#Output: true
#Explanation: The first group has [1,4], and the second group has [2,3].
#Example 2:
#Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
#Output: false
#Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
# 
#Constraints:
#	1 <= n <= 2000
#	0 <= dislikes.length <= 104
#	dislikes[i].length == 2
#	1 <= ai < bi <= n
#	All the pairs of dislikes are unique.
class Solution(object):
    def possibleBipartition(self, n, dislikes):
        """
        :type n: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        graph = [[] for _ in range(n + 1)]
        for a, b in dislikes:
            graph[a].append(b)
            graph[b].append(a)
        colors = [0] * (n + 1)
        def dfs(node, color):
            colors[node] = color
            for neighbor in graph[node]:
                if colors[neighbor] == color:
                    return False
                if not colors[neighbor] and not dfs(neighbor, -color):
                    return False
            return True
        for i in range(1, n + 1):
            if not colors[i] and not dfs(i, 1):
                return False
        return True
