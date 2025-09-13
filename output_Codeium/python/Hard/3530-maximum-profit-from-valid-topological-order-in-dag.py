# You are given a Directed Acyclic Graph (DAG) with n nodes labeled from 0 to n - 1, represented by a 2D array edges, where edges[i] = [ui, vi] indicates a directed edge from node ui to vi. Each node has an associated score given in an array score, where score[i] represents the score of node i.
# You must process the nodes in a valid topological order. Each node is assigned a 1-based position in the processing order.
# The profit is calculated by summing up the product of each node's score and its position in the ordering.
# Return the maximum possible profit achievable with an optimal topological order.
# A topological order of a DAG is a linear ordering of its nodes such that for every directed edge u → v, node u comes before v in the ordering.
# Example 1:
# Input: n = 2, edges = [[0,1]], score = [2,3]
# Output: 8
# Explanation:
# Node 1 depends on node 0, so a valid order is [0, 1].
# Node
# Processing Order
# Score
# Multiplier
# Profit Calculation
# 0
# 1st
# 2
# 1
# 2 × 1 = 2
# 1
# 2nd
# 3
# 2
# 3 × 2 = 6
# The maximum total profit achievable over all valid topological orders is 2 + 6 = 8.
# Example 2:
# Input: n = 3, edges = [[0,1],[0,2]], score = [1,6,3]
# Output: 25
# Explanation:
# Nodes 1 and 2 depend on node 0, so the most optimal valid order is [0, 2, 1].
# Node
# Processing Order
# Score
# Multiplier
# Profit Calculation
# 0
# 1st
# 1
# 1
# 1 × 1 = 1
# 2
# 2nd
# 3
# 2
# 3 × 2 = 6
# 1
# 3rd
# 6
# 3
# 6 × 3 = 18
# The maximum total profit achievable over all valid topological orders is 1 + 6 + 18 = 25.
# Constraints:
# 1 <= n == score.length <= 22
# 1 <= score[i] <= 105
# 0 <= edges.length <= n * (n - 1) / 2
# edges[i] == [ui, vi] denotes a directed edge from ui to vi.
# 0 <= ui, vi < n
# ui != vi
# The input graph is guaranteed to be a DAG.
# There are no duplicate edges.

class Solution(object):
    def maxProfit(self, n, edges, score):
        """
        :type n: int
        :type edges: List[List[int]]
        :type score: List[int]
        :rtype: int
        """    
        from collections import defaultdict
        import heapq

        # Create a graph and in-degree array
        graph = defaultdict(list)
        in_degree = [0] * n

        # Build the graph
        for u, v in edges:
            graph[u].append(v)
            in_degree[v] += 1

        # Use a priority queue to process nodes in decreasing order of score
        pq = []
        for i in range(n):
            if in_degree[i] == 0:
                heapq.heappush(pq, (-score[i], i))

        # Calculate maximum profit
        position = [0] * n
        order = 1
        while pq:
            curr_score, node = heapq.heappop(pq)
            position[node] = order
            order += 1

            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    heapq.heappush(pq, (-score[neighbor], neighbor))

        # Sum up the products of scores and positions
        max_profit = 0
        for i in range(n):
            max_profit += score[i] * position[i]

        return max_profit

