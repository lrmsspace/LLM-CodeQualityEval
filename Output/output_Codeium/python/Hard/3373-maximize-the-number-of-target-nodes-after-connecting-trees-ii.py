# There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
# You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
# Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
# Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
# Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
# Example 1:
# Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
# Output: [8,7,7,8,8]
# Explanation:
# For i = 0, connect node 0 from the first tree to node 0 from the second tree.
# For i = 1, connect node 1 from the first tree to node 4 from the second tree.
# For i = 2, connect node 2 from the first tree to node 7 from the second tree.
# For i = 3, connect node 3 from the first tree to node 0 from the second tree.
# For i = 4, connect node 4 from the first tree to node 4 from the second tree.
# Example 2:
# Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
# Output: [3,6,6,6,6]
# Explanation:
# For every i, connect node i of the first tree with any node of the second tree.
# Constraints:
# 2 <= n, m <= 105
# edges1.length == n - 1
# edges2.length == m - 1
# edges1[i].length == edges2[i].length == 2
# edges1[i] = [ai, bi]
# 0 <= ai, bi < n
# edges2[i] = [ui, vi]
# 0 <= ui, vi < m
# The input is generated such that edges1 and edges2 represent valid trees.

class Solution(object):
    def maxTargetNodes(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: List[int]
        """
        def dfs(tree, node, parent, depth, even_count, odd_count):
            if depth % 2 == 0:
                even_count[node] = even_count[parent] + 1
                odd_count[node] = odd_count[parent]
            else:
                even_count[node] = even_count[parent]
                odd_count[node] = odd_count[parent] + 1
            for neighbor in tree[node]:
                if neighbor != parent:
                    dfs(tree, neighbor, node, depth + 1, even_count, odd_count)

        def build_tree(edges, n):
            tree = [[] for _ in range(n)]
            for u, v in edges:
                tree[u].append(v)
                tree[v].append(u)
            return tree

        n = len(edges1) + 1
        m = len(edges2) + 1
        tree1 = build_tree(edges1, n)
        tree2 = build_tree(edges2, m)

        even_count1 = [0] * n
        odd_count1 = [0] * n
        even_count2 = [0] * m
        odd_count2 = [0] * m

        dfs(tree1, 0, -1, 0, even_count1, odd_count1)
        dfs(tree2, 0, -1, 0, even_count2, odd_count2)

        max_targets = [0] * n
        for i in range(n):
            max_targets[i] = max(even_count1[i] + odd_count2[j] for j in range(m))
        
        return max_targets

