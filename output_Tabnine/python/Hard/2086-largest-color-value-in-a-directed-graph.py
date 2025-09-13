#https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
#There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
#You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
#A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
#Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
# 
#Example 1:
#Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
#Output: 3
#Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
#Example 2:
#Input: colors = "a", edges = [[0,0]]
#Output: -1
#Explanation: There is a cycle from 0 to 0.
# 
#Constraints:
#	n == colors.length
#	m == edges.length
#	1 <= n <= 105
#	0 <= m <= 105
#	colors consists of lowercase English letters.
#	0 <= aj, bj < n
class Solution(object):

    def largestPathValue(self, colors, edges):

        """

        :type colors: str

        :type edges: List[List[int]]

        :rtype: int

        """
        n = len(colors)
        graph = [[] for _ in range(n)]
        indegrees = [0] * n
        for u, v in edges:
            graph[u].append(v)
            indegrees[v] += 1
        max_color_value = max(ord(c) - ord('a') + 1 for c in colors)
        color_count = [0] * max_color_value
        for i in range(n):
            color_count[ord(colors[i]) - ord('a') + 1] += 1
        max_color_count = max(color_count)
        if max_color_count == 0:
            return -1
        queue = [i for i in range(n) if indegrees[i] == 0]
        max_color_value = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                u = queue.pop(0)
                for v in graph[u]:
                    indegrees[v] -= 1
                    color_count[ord(colors[v]) - ord('a') + 1] += 1
                    max_color_count = max(max_color_count, color_count[ord(colors[v]) - ord('a') + 1])
                    if indegrees[v] == 0:
                        queue.append(v)
            max_color_value = max(max_color_value, max_color_count)
            max_color_count = max(color_count)
        return max_color_value