#https://leetcode.com/problems/shortest-path-visiting-all-nodes/
#You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
#Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
# 
#Example 1:
#Input: graph = [[1,2,3],[0],[0],[0]]
#Output: 4
#Explanation: One possible path is [1,0,2,0,3]
#Example 2:
#Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
#Output: 4
#Explanation: One possible path is [0,1,4,2,3]
# 
#Constraints:
#	n == graph.length
#	1 <= n <= 12
#	0 <= graph[i].length < n
#	graph[i] does not contain i.
#	If graph[a] contains b, then graph[b] contains a.
#	The input graph is always connected.
class Solution(object):
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        from collections import deque

        n = len(graph)
        all_visited = (1 << n) - 1
        queue = deque([(i, 1 << i, 0) for i in range(n)])
        visited = set((i, 1 << i) for i in range(n))

        while queue:
            node, mask, dist = queue.popleft()
            if mask == all_visited:
                return dist

            for neighbor in graph[node]:
                next_mask = mask | (1 << neighbor)
                if (neighbor, next_mask) not in visited:
                    visited.add((neighbor, next_mask))
                    queue.append((neighbor, next_mask, dist + 1))

        return -1