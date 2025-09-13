# You are given two integers, n and threshold, as well as a directed weighted graph of n nodes numbered from 0 to n - 1. The graph is represented by a 2D integer array edges, where edges[i] = [Ai, Bi, Wi] indicates that there is an edge going from node Ai to node Bi with weight Wi.
# You have to remove some edges from this graph (possibly none), so that it satisfies the following conditions:
# Node 0 must be reachable from all other nodes.
# The maximum edge weight in the resulting graph is minimized.
# Each node has at most threshold outgoing edges.
# Return the minimum possible value of the maximum edge weight after removing the necessary edges. If it is impossible for all conditions to be satisfied, return -1.
# Example 1:
# Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
# Output: 1
# Explanation:
# Remove the edge 2 -> 0. The maximum weight among the remaining edges is 1.
# Example 2:
# Input: n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1
# Output: -1
# Explanation: 
# It is impossible to reach node 0 from node 2.
# Example 3:
# Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1
# Output: 2
# Explanation: 
# Remove the edges 1 -> 3 and 1 -> 4. The maximum weight among the remaining edges is 2.
# Example 4:
# Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[4,0,1]], threshold = 1
# Output: -1
# Constraints:
# 2 <= n <= 105
# 1 <= threshold <= n - 1
# 1 <= edges.length <= min(105, n * (n - 1) / 2).
# edges[i].length == 3
# 0 <= Ai, Bi < n
# Ai != Bi
# 1 <= Wi <= 106
# There may be multiple edges between a pair of nodes, but they must have unique weights.

class Solution(object):
    def minMaxWeight(self, n, edges, threshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        from collections import defaultdict, deque
        import heapq

        # Build the graph
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))

        # Function to check if we can reach node 0 with max weight limit
        def canReachWithMaxWeight(max_weight):
            indegree = [0] * n
            outdegree = [0] * n
            for u in range(n):
                for v, w in graph[u]:
                    if w <= max_weight:
                        indegree[v] += 1
                        outdegree[u] += 1
            
            # Check outdegree constraint
            if any(outdegree[i] > threshold for i in range(n)):
                return False
            
            # BFS to check reachability from all nodes to node 0
            queue = deque([0])
            visited = set([0])
            while queue:
                node = queue.popleft()
                for neighbor, weight in graph[node]:
                    if weight <= max_weight and neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
            
            return len(visited) == n

        # Binary search over the edge weights
        left, right = 1, max(w for _, _, w in edges)
        result = -1
        
        while left <= right:
            mid = (left + right) // 2
            if canReachWithMaxWeight(mid):
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return result        