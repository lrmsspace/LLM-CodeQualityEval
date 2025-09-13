# There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
# You must connect one node from the first tree with another node from the second tree with an edge.
# Return the minimum possible diameter of the resulting tree.
# The diameter of a tree is the length of the longest path between any two nodes in the tree.
# Example 1:
# Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
# Output: 3
# Explanation:
# We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
# Example 2:
# Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
# Output: 5
# Explanation:
# We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.
# Constraints:
# 1 <= n, m <= 105
# edges1.length == n - 1
# edges2.length == m - 1
# edges1[i].length == edges2[i].length == 2
# edges1[i] = [ai, bi]
# 0 <= ai, bi < n
# edges2[i] = [ui, vi]
# 0 <= ui, vi < m
# The input is generated such that edges1 and edges2 represent valid trees.

from collections import deque

class Solution(object):
    def minimumDiameterAfterMerge(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: int
        """
        MOD = 10**9 + 7
        
        def build_graph(edges):
            n = len(edges) + 1
            graph = [[] for _ in range(n)]
            for u, v in edges:
                graph[u].append(v)
                graph[v].append(u)
            return graph

        def bfs(start, graph):
            dist = [-1] * len(graph)
            q = deque([start])
            dist[start] = 0
            while q:
                u = q.popleft()
                for v in graph[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)
            max_dist = max(dist)
            far_node = dist.index(max_dist)
            return far_node, max_dist

        def get_diameter_and_radius(graph):
            # Get diameter using two BFS
            u, _ = bfs(0, graph)
            v, diameter = bfs(u, graph)

            # Get radius (minimum of maximum depth from any node on the center path)
            # We can use multi-source BFS to find minimum distance to furthest node
            def multi_bfs_center(graph):
                n = len(graph)
                degree = [len(adj) for adj in graph]
                q = deque(i for i in range(n) if degree[i] == 1)
                layer = 0
                removed = 0
                centers = list(range(n))
                while removed < n:
                    next_q = deque()
                    new_centers = []
                    for node in q:
                        removed += 1
                        for nei in graph[node]:
                            degree[nei] -= 1
                            if degree[nei] == 1:
                                next_q.append(nei)
                                new_centers.append(nei)
                    if removed < n:
                        centers = new_centers
                    layer += 1
                return centers

            centers = multi_bfs_center(graph)
            # From each center, compute max depth
            _, radius = bfs(centers[0], graph)
            return diameter, radius

        graph1 = build_graph(edges1)
        graph2 = build_graph(edges2)

        diameter1, radius1 = get_diameter_and_radius(graph1)
        diameter2, radius2 = get_diameter_and_radius(graph2)

        merged_diameter = max(diameter1, diameter2, radius1 + radius2 + 1)
        return merged_diameter