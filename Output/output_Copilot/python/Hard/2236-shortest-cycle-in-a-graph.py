#https://leetcode.com/problems/shortest-cycle-in-a-graph/
#There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
#Return the length of the shortest cycle in the graph. If no cycle exists, return -1.
#A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.
# 
#Example 1:
#Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
#Output: 3
#Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
#Example 2:
#Input: n = 4, edges = [[0,1],[0,2]]
#Output: -1
#Explanation: There are no cycles in this graph.
# 
#Constraints:
#	2 <= n <= 1000
#	1 <= edges.length <= 1000
#	edges[i].length == 2
#	0 <= ui, vi < n
#	ui != vi
#	There are no repeated edges.
class Solution(object):
    def findShortestCycle(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        def bfs(start):
            queue = [(start, -1, 0)]        
            visited = set()
            visited.add(start)
            while queue:
                node, parent, dist = queue.pop(0)
                for neighbor in graph[node]:
                    if neighbor == parent:
                        continue
                    if neighbor in visited:
                        return dist + 1
                    visited.add(neighbor)
                    queue.append((neighbor, node, dist + 1))
            return float('inf')
        shortest_cycle = float('inf')
        for i in range(n):
            cycle_length = bfs(i)
            shortest_cycle = min(shortest_cycle, cycle_length)
        return shortest_cycle if shortest_cycle != float('inf') else -1