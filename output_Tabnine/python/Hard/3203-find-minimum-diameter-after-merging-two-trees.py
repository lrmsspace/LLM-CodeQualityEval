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

class Solution(object):
    def minimumDiameterAfterMerge(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: int
        """
        # Build the adjacency lists for each tree
        adj1 = [[] for _ in range(len(edges1) + 1)]
        adj2 = [[] for _ in range(len(edges2) + 1)]
        
        for i, (u, v) in enumerate(edges1):
            adj1[u].append(v)
            adj1[v].append(u)
        
        for i, (u, v) in enumerate(edges2):
            adj2[u].append(v)
            adj2[v].append(u)
        
        # Find the roots of the trees
        root1 = self.find_root(adj1)
        root2 = self.find_root(adj2)
        
        # Union-find to connect the roots
        self.union(adj1, adj2, root1, root2)
        
        # Count the number of nodes in the resulting tree
        count = [0] * (len(adj1) + len(adj2))
        self.dfs(adj1, root1, count)
        self.dfs(adj2, root2, count)
        
        return max(count) - 1