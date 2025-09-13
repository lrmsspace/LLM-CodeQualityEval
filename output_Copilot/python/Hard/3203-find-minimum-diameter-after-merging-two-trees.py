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
        def dfs(tree, node, parent):
            max_depth = 0
            second_max_depth = 0
            
            for neighbor in tree[node]:
                if neighbor != parent:
                    depth = dfs(tree, neighbor, node) + 1
                    if depth > max_depth:
                        second_max_depth = max_depth
                        max_depth = depth
                    elif depth > second_max_depth:
                        second_max_depth = depth
            
            return max_depth
        
        def build_tree(edges):
            tree = [[] for _ in range(len(edges) + 1)]
            for a, b in edges:
                tree[a].append(b)
                tree[b].append(a)
            return tree
        
        tree1 = build_tree(edges1)
        tree2 = build_tree(edges2)
        
        diameter1 = dfs(tree1, 0, -1)
        diameter2 = dfs(tree2, 0, -1)
        
        return diameter1 + diameter2 + 1
            