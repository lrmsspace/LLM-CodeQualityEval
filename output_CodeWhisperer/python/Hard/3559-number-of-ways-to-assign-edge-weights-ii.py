# There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
# Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
# The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
# You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
# Return an array answer, where answer[i] is the number of valid assignments for queries[i].
# Since the answer may be large, apply modulo 109 + 7 to each answer[i].
# Note: For each query, disregard all edges not in the path between node ui and vi.
# Example 1:
# Input: edges = [[1,2]], queries = [[1,1],[1,2]]
# Output: [0,1]
# Explanation:
# Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
# Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
# Example 2:
# Input: edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]
# Output: [2,1,4]
# Explanation:
# Query [1,4]: The path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
# Query [3,4]: The path from Node 3 to Node 4 consists of one edge (3 → 4). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
# Query [2,5]: The path from Node 2 to Node 5 consists of three edges (2 → 1, 1 → 3, and 3 → 5). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.
# Constraints:
# 2 <= n <= 105
# edges.length == n - 1
# edges[i] == [ui, vi]
# 1 <= queries.length <= 105
# queries[i] == [ui, vi]
# 1 <= ui, vi <= n
# edges represents a valid tree.

class Solution(object):
    def assignEdgeWeights(self, edges, queries):
        """
        :type edges: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        # Initialize the graph
        graph = [[] for _ in range(len(edges) + 2)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # Initialize the parent and level arrays
        parent = [[-1] * 3 for _ in range(len(edges) + 2)]
        level = [[0] * 3 for _ in range(len(edges) + 2)]

        # Perform DFS to find the parent and level of each node
        def dfs(node, p, l):
            for child in graph[node]:
                if child != p:
                    parent[child][0] = node
                    level[child][0] = l + 1
                    dfs(child, node, l + 1)

        dfs(1, -1, 0)

        # Process each query
        result = []
        for start, end in queries:
            count = 0
            for weight in range(1, 3):
                if level[start][weight] == 0 or level[end][weight] == 0:
                    continue
                if level[start][weight] > level[end][weight]:
                    start, end = end, start
                current = start
                while current != end:
                    if level[current][weight] < level[end][weight]:
                        current = parent[current][weight]
                    else:
                        count += 1
                        current = parent[current][weight]
            result.append(count)

        return result

        