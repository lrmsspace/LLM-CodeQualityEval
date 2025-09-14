# You are given an array of integers nums of size n and a positive integer threshold.
# There is a graph consisting of n nodes with the ith node having a value of nums[i]. Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.
# Return the number of connected components in this graph.
# A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
# The term lcm(a, b) denotes the least common multiple of a and b.
# Example 1:
# Input: nums = [2,4,8,3,9], threshold = 5
# Output: 4
# Explanation: 
# The four connected components are (2, 4), (3), (8), (9).
# Example 2:
# Input: nums = [2,4,8,3,9,12], threshold = 10
# Output: 2
# Explanation: 
# The two connected components are (2, 3, 4, 8, 9), and (12).
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109
# All elements of nums are unique.
# 1 <= threshold <= 2 * 105

class Solution(object):
    def countComponents(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        from math import gcd
        from collections import defaultdict

        def lcm(a, b):
            return a * (b // gcd(a, b))

        n = len(nums)
        graph = defaultdict(list)

        # Build the graph based on the lcm condition
        for i in range(n):
            for j in range(i + 1, n):
                if lcm(nums[i], nums[j]) <= threshold:
                    graph[nums[i]].append(nums[j])
                    graph[nums[j]].append(nums[i])

        visited = set()
        components = 0

        def dfs(node):
            stack = [node]
            while stack:
                current = stack.pop()
                for neighbor in graph[current]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        stack.append(neighbor)

        # Count connected components
        for num in nums:
            if num not in visited:
                visited.add(num)
                dfs(num)
                components += 1

        return components
        