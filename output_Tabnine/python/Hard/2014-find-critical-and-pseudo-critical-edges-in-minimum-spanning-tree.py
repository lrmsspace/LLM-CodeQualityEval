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
        # Step 1: Build adjacency list
        adj_list = [[] for _ in range(n)]
        for u, v, w in edges:
            adj_list[u].append((v, w))
            adj_list[v].append((u, w))
        
        # Step 2: Initialize parent, rank, and distance arrays
        parent = [i for i in range(n)]
        rank = [0] * n
        distance = [0] * n
        
        # Step 3: Find minimum spanning tree using Kruskal's algorithm
        mst_edges = []
        total_weight = 0
        for u, v, w in sorted(edges, key=lambda x: x[2]):
            if self.find(parent, u) == self.find(parent, v):
                continue
            mst_edges.append((u, v, w))
            total_weight += w
            self.union(parent, rank, u, v)
            distance[u] += w
        
        # Step 4: Find critical and pseudo-critical edges
        critical_edges = []
        pseudo_critical_edges = []
        for i, (u, v, w) in enumerate(mst_edges):
            # Check if deleting edge (u, v) would increase the total weight
            new_distance = distance[:u] + [distance[u] - w] + distance[u+1:v] + [distance[v] - w] + distance[v+1:]
            new_total_weight = sum(new_distance)
            
            # If deleting edge (u, v) would increase the total weight, it is a critical edge
            if new_total_weight > total_weight:
                critical_edges.append(i)
            # If deleting edge (u, v) would not increase the total weight, it is a pseudo-critical edge
            else:
                pseudo_critical_edges.append(i)
        
        return [critical_edges, pseudo_critical_edges]
        