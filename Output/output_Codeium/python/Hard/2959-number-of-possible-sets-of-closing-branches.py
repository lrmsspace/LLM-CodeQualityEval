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
        def is_valid(closed, n, maxDistance, roads):
            """
            Check if the given set of closed branches is valid.
            """
            graph = [[] for _ in range(n)]
            for u, v, d in roads:
                if u not in closed and v not in closed:
                    graph[u].append((v, d))
                    graph[v].append((u, d))
            for i in range(n):
                if i not in closed:
                    queue = [(i, 0)]
                    visited = set()
                    while queue:
                        node, dist = queue.pop(0)
                        if node in visited:
                            continue
                        visited.add(node)
                        if dist > maxDistance:
                            return False
                        for neighbor, ndist in graph[node]:
                            queue.append((neighbor, dist + ndist))
            return True
        
        count = 0
        for i in range(1 << n):
            closed = set()
            for j in range(n):
                if i & (1 << j):
                    closed.add(j)
            if is_valid(closed, n, maxDistance, roads):
                count += 1
        return count
