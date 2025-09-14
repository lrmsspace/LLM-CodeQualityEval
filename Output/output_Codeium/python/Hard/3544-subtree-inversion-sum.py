# You are given an undirected tree rooted at node 0, with n nodes numbered from 0 to n - 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates an edge between nodes ui and vi.
# You are also given an integer array nums of length n, where nums[i] represents the value at node i, and an integer k.
# You may perform inversion operations on a subset of nodes subject to the following rules:
# Subtree Inversion Operation:
# When you invert a node, every value in the subtree rooted at that node is multiplied by -1.
# Distance Constraint on Inversions:
# You may only invert a node if it is "sufficiently far" from any other inverted node.
# Specifically, if you invert two nodes a and b such that one is an ancestor of the other (i.e., if LCA(a, b) = a or LCA(a, b) = b), then the distance (the number of edges on the unique path between them) must be at least k.
# Return the maximum possible sum of the tree's node values after applying inversion operations.
# Example 1:
# Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], nums = [4,-8,-6,3,7,-2,5], k = 2
# Output: 27
# Explanation:
# Apply inversion operations at nodes 0, 3, 4 and 6.
# The final nums array is [-4, 8, 6, 3, 7, 2, 5], and the total sum is 27.
# Example 2:
# Input: edges = [[0,1],[1,2],[2,3],[3,4]], nums = [-1,3,-2,4,-5], k = 2
# Output: 9
# Explanation:
# Apply the inversion operation at node 4.
# The final nums array becomes [-1, 3, -2, 4, 5], and the total sum is 9.
# Example 3:
# Input: edges = [[0,1],[0,2]], nums = [0,-1,-2], k = 3
# Output: 3
# Explanation:
# Apply inversion operations at nodes 1 and 2.
# Constraints:
# 2 <= n <= 5 * 104
# edges.length == n - 1
# edges[i] = [ui, vi]
# 0 <= ui, vi < n
# nums.length == n
# -5 * 104 <= nums[i] <= 5 * 104
# 1 <= k <= 50
# The input is generated such that edges represents a valid tree.

class Solution(object):
    def subtreeInversionSum(self, edges, nums, k):
        """
        :type edges: List[List[int]]
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        from collections import defaultdict, deque

        def dfs(node, graph, nums, visited):
            stack = [(node, 0)]
            subtree_sum = 0
            while stack:
                current, state = stack.pop()
                if state == 0:  # Pre-visit
                    if visited[current]:
                        continue
                    visited[current] = True
                    subtree_sum += nums[current]
                    stack.append((current, 1))  # Add post-visit
                    for neighbor in graph[current]:
                        if not visited[neighbor]:
                            stack.append((neighbor, 0))  # Add child
                else:  # Post-visit, subtract value
                    subtree_sum -= nums[current]
            return subtree_sum

        def can_invert(node, parent, graph, nums, k, visited, distances):
            if visited[node]:
                return True
            if distances[node] < k:
                return False
            visited[node] = True
            for neighbor in graph[node]:
                if neighbor != parent and not can_invert(neighbor, node, graph, nums, k, visited, distances):
                    return False
            return True

        def compute_distances(n, graph):
            distances = [-1] * n
            queue = deque([0])
            distances[0] = 0
            while queue:
                node = queue.popleft()
                for neighbor in graph[node]:
                    if distances[neighbor] == -1:
                        distances[neighbor] = distances[node] + 1
                        queue.append(neighbor)
            return distances

        def max_inversion_sum(graph, nums, k):
            n = len(nums)
            visited = [False] * n
            distances = compute_distances(n, graph)
            max_sum = 0

            for i in range(n):
                if can_invert(i, -1, graph, nums, k, visited, distances):
                    max_sum += dfs(i, graph, nums, [False] * n)

            return max_sum

        # Build the graph
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        return max_inversion_sum(graph, nums, k)

