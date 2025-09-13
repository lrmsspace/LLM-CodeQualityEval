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
        # Create an adjacency list to represent the tree
        graph = [[] for _ in range(len(nums))]
        for u, v, _ in edges:
            graph[u].append(v)
            graph[v].append(u)

        # Initialize the memoization dictionary
        memo = {}

        # Define the DFS function to find the longest special path
        def dfs(node, parent):
            # Check if the result is already memoized
            key = (node, parent)
            if key in memo:
                return memo[key]

            # Initialize the maximum length and minimum number of nodes
            max_length = 0
            min_nodes = 1

            # Iterate over the children of the current node
            for child in graph[node]:
                if child != parent:
                    # Recursively find the longest special path for the child
                    child_length, child_nodes = dfs(child, node)

                    # Check if the values of the nodes in the child path are unique
                    if nums[child] != nums[node]:
                        # Update the maximum length and minimum number of nodes
                        max_length = max(max_length, child_length + 1)
                        min_nodes = max(min_nodes, child_nodes)

            # Memoize the result
            memo[key] = (max_length, min_nodes)

            return max_length, min_nodes

        # Find the longest special path starting from the root node (0)
        result = dfs(0, -1)

        # Return the length of the longest special path and the minimum number of nodes
        return [result[0], result[1]] if result[0] > 0 else [0, 1]
        