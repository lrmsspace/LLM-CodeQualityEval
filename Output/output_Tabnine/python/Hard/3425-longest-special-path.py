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
        # Step 1: Build the adjacency list
        n = len(edges)
        adj_list = [[] for _ in range(n)]
        for u, v, length in edges:
            adj_list[u].append((v, length))
            adj_list[v].append((u, length))
        
        # Step 2: Initialize the depth and parent arrays
        depth = [0] * n
        parent = [-1] * n
        
        # Step 3: Perform a depth-first search to find the depth and parent of each node
        def dfs(node, parent):
            nonlocal depth
            depth[node] = 1
            for neighbor, length in adj_list[node]:
                if neighbor!= parent:
                    dfs(neighbor, node)
                    depth[node] = max(depth[node], depth[neighbor] + length)
        
        dfs(0, -1)
        # Step 4: Perform another depth-first search to find the maximum depth and the minimum number of nodes
        max_depth = max(depth)
        min_nodes = n
        for node in range(n):
            if depth[node] == max_depth:
                min_nodes = min(min_nodes, dfs_min_nodes(node, max_depth))
        
        return [max_depth, min_nodes]
        