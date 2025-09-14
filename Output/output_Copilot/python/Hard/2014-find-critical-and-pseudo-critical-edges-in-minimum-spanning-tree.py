#https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
#Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
#Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
#Note that you can return the indices of the edges in any order.
# 
#Example 1:
#Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
#Output: [[0,1],[2,3,4,5]]
#Explanation: The figure above describes the graph.
#The following figure shows all the possible MSTs:
#Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
#The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
#Example 2:
#Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
#Output: [[],[0,1,2,3]]
#Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
# 
#Constraints:
#	2 <= n <= 100
#	1 <= edges.length <= min(200, n * (n - 1) / 2)
#	edges[i].length == 3
#	0 <= ai < bi < n
#	1 <= weighti <= 1000
#	All pairs (ai, bi) are distinct.
class Solution(object):
    def findCriticalAndPseudoCriticalEdges(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[List[int]]
        """
        edges = [[a, b, w, i] for i, (a, b, w) in enumerate(edges)]
        edges.sort(key=lambda x: x[2])

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            parent[find(x)] = find(y)

        def kruskal(n, edges, skip_edge=None, force_edge=None):
            nonlocal parent
            parent = list(range(n))
            total_weight = 0
            edge_count = 0

            if force_edge is not None:
                a, b, w, _ = force_edge
                union(a, b)
                total_weight += w
                edge_count += 1

            for a, b, w, _ in edges:
                if (a, b) == skip_edge or find(a) == find(b):
                    continue
                union(a, b)
                total_weight += w
                edge_count += 1

            return total_weight if edge_count == n - 1 else float('inf')

        mst_weight = kruskal(n, edges)
        critical_edges = []
        pseudo_critical_edges = []

        for i in range(len(edges)):
            a, b, w, _ = edges[i]
            if kruskal(n, edges, skip_edge=(a, b)) > mst_weight:
                critical_edges.append(edges[i][3])
            elif kruskal(n, edges) == mst_weight:
                pseudo_critical_edges.append(edges[i][3])

        return [sorted(critical_edges), sorted(pseudo_critical_edges)]        