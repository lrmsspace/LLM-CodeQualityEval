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
        # Initialize the graph with n nodes
        graph = [[] for _ in range(n+1)]
        
        # Build the graph based on the dislikes
        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)
        
        # Initialize the color of each node as unvisited
        color = [-1] * (n+1)
        
        # Perform depth-first search (DFS) to check if it's possible to divide the nodes into two groups
        def dfs(node, group):
            color[node] = group
            
            for neighbor in graph[node]:
                if color[neighbor] == -1:
                    if not dfs(neighbor, 1 - group):
                        return False
                elif color[neighbor] == group:
                    return False
            
            return True
        
        # Start DFS from each node
        for i in range(1, n+1):
            if color[i] == -1:
                if not dfs(i, 0):
                    return False
        
        return True
        