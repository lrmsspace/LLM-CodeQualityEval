#https://leetcode.com/problems/redundant-connection/
#In this problem, a tree is an undirected graph that is connected and has no cycles.
#You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
#Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
# 
#Example 1:
#Input: edges = [[1,2],[1,3],[2,3]]
#Output: [2,3]
#Example 2:
#Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
#Output: [1,4]
# 
#Constraints:
#	n == edges.length
#	3 <= n <= 1000
#	edges[i].length == 2
#	1 <= ai < bi <= edges.length
#	ai != bi
#	There are no repeated edges.
#	The given graph is connected.
class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        graph = {i: [] for i in range(1, len(edges) + 1)}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        for u, v in reversed(edges):
            graph[u].remove(v)
            graph[v].remove(u)
            if self.is_connected(graph):
                return [u, v]
    
    def is_connected(self, graph):
        visited = set()
        self._dfs(graph, 1, visited)
        return len(visited) == len(graph)
    
    def _dfs(self, graph, node, visited):
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                self._dfs(graph, neighbor, visited)
        return
    
        
