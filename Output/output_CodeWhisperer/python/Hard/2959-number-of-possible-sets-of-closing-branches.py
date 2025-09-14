# There is a company with n branches across the country, some of which are connected by roads. Initially, all branches are reachable from each other by traveling some roads.
# The company has realized that they are spending an excessive amount of time traveling between their branches. As a result, they have decided to close down some of these branches (possibly none). However, they want to ensure that the remaining branches have a distance of at most maxDistance from each other.
# The distance between two branches is the minimum total traveled length needed to reach one branch from another.
# You are given integers n, maxDistance, and a 0-indexed 2D array roads, where roads[i] = [ui, vi, wi] represents the undirected road between branches ui and vi with length wi.
# Return the number of possible sets of closing branches, so that any branch has a distance of at most maxDistance from any other.
# Note that, after closing a branch, the company will no longer have access to any roads connected to it.
# Note that, multiple roads are allowed.
# Example 1:
# Input: n = 3, maxDistance = 5, roads = [[0,1,2],[1,2,10],[0,2,10]]
# Output: 5
# Explanation: The possible sets of closing branches are:
# - The set [2], after closing, active branches are [0,1] and they are reachable to each other within distance 2.
# - The set [0,1], after closing, the active branch is [2].
# - The set [1,2], after closing, the active branch is [0].
# - The set [0,2], after closing, the active branch is [1].
# - The set [0,1,2], after closing, there are no active branches.
# It can be proven, that there are only 5 possible sets of closing branches.
# Example 2:
# Input: n = 3, maxDistance = 5, roads = [[0,1,20],[0,1,10],[1,2,2],[0,2,2]]
# Output: 7
# Explanation: The possible sets of closing branches are:
# - The set [], after closing, active branches are [0,1,2] and they are reachable to each other within distance 4.
# - The set [0], after closing, active branches are [1,2] and they are reachable to each other within distance 2.
# - The set [1], after closing, active branches are [0,2] and they are reachable to each other within distance 2.
# - The set [0,1], after closing, the active branch is [2].
# - The set [1,2], after closing, the active branch is [0].
# - The set [0,2], after closing, the active branch is [1].
# - The set [0,1,2], after closing, there are no active branches.
# It can be proven, that there are only 7 possible sets of closing branches.
# Example 3:
# Input: n = 1, maxDistance = 10, roads = []
# Output: 2
# Explanation: The possible sets of closing branches are:
# - The set [], after closing, the active branch is [0].
# - The set [0], after closing, there are no active branches.
# It can be proven, that there are only 2 possible sets of closing branches.
# Constraints:
# 1 <= n <= 10
# 1 <= maxDistance <= 105
# 0 <= roads.length <= 1000
# roads[i].length == 3
# 0 <= ui, vi <= n - 1
# ui != vi
# 1 <= wi <= 1000
# All branches are reachable from each other by traveling some roads.

class Solution(object):
    def numberOfSets(self, n, maxDistance, roads):
        """
        :type n: int
        :type maxDistance: int
        :type roads: List[List[int]]
        :rtype: int
        """
        # Create a graph representation of the branches
        graph = [[] for _ in range(n)]
        for u, v, w in roads:
            graph[u].append((v, w))
            graph[v].append((u, w))

        # Function to check if a branch is reachable within the maximum distance
        def is_reachable(branch, visited):
            if branch in visited:
                return
            visited.add(branch)
            for neighbor, distance in graph[branch]:
                if distance <= maxDistance:
                    is_reachable(neighbor, visited)

        # Iterate through all possible combinations of branches to close
        result = 0
        for mask in range(1 << n):
            visited = set()
            for branch in range(n):
                if mask & (1 << branch):
                    is_reachable(branch, visited)

            # If all branches are reachable, increment the result
            if len(visited) == n:
                result += 1

        return result        