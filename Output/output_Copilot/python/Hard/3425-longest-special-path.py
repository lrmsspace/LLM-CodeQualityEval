# You are given an undirected tree rooted at node 0 with n nodes numbered from 0 to n - 1, represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.
# A special path is defined as a downward path from an ancestor node to a descendant node such that all the values of the nodes in that path are unique.
# Note that a path may start and end at the same node.
# Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.
# Example 1:
# Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], nums = [2,1,2,1,3,1]
# Output: [6,2]
# Explanation:
# In the image below, nodes are colored by their corresponding values in nums
# The longest special paths are 2 -> 5 and 0 -> 1 -> 4, both having a length of 6. The minimum number of nodes across all longest special paths is 2.
# Example 2:
# Input: edges = [[1,0,8]], nums = [2,2]
# Output: [0,1]
# Explanation:
# The longest special paths are 0 and 1, both having a length of 0. The minimum number of nodes across all longest special paths is 1.
# Constraints:
# 2 <= n <= 5 * 104
# edges.length == n - 1
# edges[i].length == 3
# 0 <= ui, vi < n
# 1 <= lengthi <= 103
# nums.length == n
# 0 <= nums[i] <= 5 * 104
# The input is generated such that edges represents a valid tree.

class Solution(object):
    def longestSpecialPath(self, edges, nums):
        """
        :type edges: List[List[int]]
        :type nums: List[int]
        :rtype: List[int]
        """
        from collections import defaultdict, deque

        graph = defaultdict(list)
        for u, v, length in edges:
            graph[u].append((v, length))
            graph[v].append((u, length))

        n = len(nums)
        max_length = 0
        min_nodes = float('inf')

        def bfs(start):
            nonlocal max_length, min_nodes
            queue = deque([(start, -1, 0)])
            visited = set()
            path_length = 0
            path_nodes = 0
            unique_values = set()
            while queue:
                node, parent, length = queue.popleft()
                if nums[node] in unique_values:
                    continue
                unique_values.add(nums[node])
                path_length += length
                path_nodes += 1
                visited.add(node)

                for neighbor, edge_length in graph[node]:
                    if neighbor != parent and neighbor not in visited:
                        queue.append((neighbor, node, edge_length))
            if path_length > max_length:
                max_length = path_length
                min_nodes = path_nodes
            elif path_length == max_length:
                min_nodes = min(min_nodes, path_nodes)
        for i in range(n):
            if nums[i] not in set(nums[:i]):
                bfs(i)
        return [max_length, min_nodes] if max_length > 0 else [0, 1]
        