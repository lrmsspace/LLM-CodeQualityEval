#https://leetcode.com/problems/shortest-path-with-alternating-colors/
#You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
#You are given two arrays redEdges and blueEdges where:
#	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
#	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
#Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
# 
#Example 1:
#Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
#Output: [0,1,-1]
#Example 2:
#Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
#Output: [0,1,-1]
# 
#Constraints:
#	1 <= n <= 100
#	0 <= redEdges.length, blueEdges.length <= 400
#	redEdges[i].length == blueEdges[j].length == 2
#	0 <= ai, bi, uj, vj < n
class Solution(object):
    def shortestAlternatingPaths(self, n, redEdges, blueEdges):
        """
        :type n: int
        :type redEdges: List[List[int]]
        :type blueEdges: List[List[int]]
        :rtype: List[int]
        """
        graph = [[] for _ in range(n)]
        for u, v in redEdges:
            graph[u].append((v, 0))
        for u, v in blueEdges:
            graph[u].append((v, 1))
        dist = [[float('inf')] * 2 for _ in range(n)]
        dist[0][0] = dist[0][1] = 0
        queue = [(0, 0), (0, 1)]
        while queue:
            node, color = queue.pop(0)
            for neighbor, neighbor_color in graph[node]:
                if neighbor_color != color and dist[neighbor][neighbor_color] > dist[node][color] + 1:
                    dist[neighbor][neighbor_color] = dist[node][color] + 1
                    queue.append((neighbor, neighbor_color))
        return [-1 if dist[i][0] == float('inf') else dist[i][0] for i in range(n)]
