# You are given an undirected connected graph of n nodes, numbered from 0 to n - 1. Each node is connected to at most 2 other nodes.
# The graph consists of m edges, represented by a 2D array edges, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi.
# You have to assign a unique value from 1 to n to each node. The value of an edge will be the product of the values assigned to the two nodes it connects.
# Your score is the sum of the values of all edges in the graph.
# Return the maximum score you can achieve.
# Example 1:
# Input: n = 4, edges = [[0,1],[1,2],[2,3]]
# Output: 23
# Explanation:
# The diagram above illustrates an optimal assignment of values to nodes. The sum of the values of the edges is: (1 * 3) + (3 * 4) + (4 * 2) = 23.
# Example 2:
# Input: n = 6, edges = [[0,3],[4,5],[2,0],[1,3],[2,4],[1,5]]
# Output: 82
# Explanation:
# The diagram above illustrates an optimal assignment of values to nodes. The sum of the values of the edges is: (1 * 2) + (2 * 4) + (4 * 6) + (6 * 5) + (5 * 3) + (3 * 1) = 82.
# Constraints:
# 1 <= n <= 5 * 104
# m == edges.length
# 1 <= m <= n
# edges[i].length == 2
# 0 <= ai, bi < n
# ai != bi
# There are no repeated edges.
# The graph is connected.
# Each node is connected to at most 2 other nodes.

class Solution(object):
    def maxScore(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        from collections import defaultdict
        
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        max_score = 0

        def dfs(node, parent):
            nonlocal max_score
            visited[node] = True
            values = [node + 1]
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    child_values = dfs(neighbor, node)
                    values.extend(child_values)
            if len(values) > 1:
                values.sort()
                score = sum(values[i] * values[i + 1] for i in range(len(values) - 1))
                max_score = max(max_score, score)
            return values
        for i in range(n):
            if not visited[i]:
                dfs(i, -1)
        return max_score    
        