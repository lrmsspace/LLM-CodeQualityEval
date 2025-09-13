# You are given an integer n and an undirected tree rooted at node 0 with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi] indicates an edge from node ui to vi .
# Each node i has an associated cost given by cost[i], representing the cost to traverse that node.
# The score of a path is defined as the sum of the costs of all nodes along the path.
# Your goal is to make the scores of all root-to-leaf paths equal by increasing the cost of any number of nodes by any non-negative amount.
# Return the minimum number of nodes whose cost must be increased to make all root-to-leaf path scores equal.
# Example 1:
# Input: n = 3, edges = [[0,1],[0,2]], cost = [2,1,3]
# Output: 1
# Explanation:
# There are two root-to-leaf paths:
# Path 0 → 1 has a score of 2 + 1 = 3.
# Path 0 → 2 has a score of 2 + 3 = 5.
# To make all root-to-leaf path scores equal to 5, increase the cost of node 1 by 2.
# Only one node is increased, so the output is 1.
# Example 2:
# Input: n = 3, edges = [[0,1],[1,2]], cost = [5,1,4]
# Output: 0
# Explanation:
# There is only one root-to-leaf path:
# Path 0 → 1 → 2 has a score of 5 + 1 + 4 = 10.
# Since only one root-to-leaf path exists, all path costs are trivially equal, and the output is 0.
# Example 3:
# Input: n = 5, edges = [[0,4],[0,1],[1,2],[1,3]], cost = [3,4,1,1,7]
# Output: 1
# Explanation:
# There are three root-to-leaf paths:
# Path 0 → 4 has a score of 3 + 7 = 10.
# Path 0 → 1 → 2 has a score of 3 + 4 + 1 = 8.
# Path 0 → 1 → 3 has a score of 3 + 4 + 1 = 8.
# To make all root-to-leaf path scores equal to 10, increase the cost of node 1 by 2. Thus, the output is 1.
# Constraints:
# 2 <= n <= 105
# edges.length == n - 1
# edges[i] == [ui, vi]
# 0 <= ui, vi < n
# cost.length == n
# 1 <= cost[i] <= 109
# The input is generated such that edges represents a valid tree.

class Solution(object):
    def minIncrease(self, n, edges, cost):
        """
        :type n: int
        :type edges: List[List[int]]
        :type cost: List[int]
        :rtype: int
        """
        from collections import defaultdict

        # Build the tree representation using adjacency list
        tree = defaultdict(list)
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        # Helper function to perform DFS and calculate the scores of paths
        def dfs(node, parent):
            max_score = 0  # Max score from root to any leaf in this subtree
            leaf_scores = []  # Scores of all leaf paths in this subtree
            for neighbor in tree[node]:
                if neighbor != parent:
                    score, leaves = dfs(neighbor, node)
                    max_score = max(max_score, score)
                    leaf_scores.extend(leaves)

            if not leaf_scores:
                # Current node is a leaf
                leaf_scores.append(cost[node])
            else:
                # Include current node's cost in all leaf path scores
                leaf_scores = [score + cost[node] for score in leaf_scores]

            return max(leaf_scores), leaf_scores

        # Calculate scores of all root-to-leaf paths
        _, leaf_scores = dfs(0, -1)

        # Determine the minimum number of nodes to increase
        max_score = max(leaf_scores)
        increase_count = sum(1 for score in leaf_scores if score < max_score)

        return increase_count

