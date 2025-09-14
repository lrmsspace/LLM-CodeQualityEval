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
        n = len(graph)
        q = deque()
        visited = set()
        for i in range(n):
            q.append((1 << i, i))
            visited.add((1 << i, i))
        steps = 0
        while q:
            for i in range(len(q)):
                mask, node = q.popleft()
                if mask == (1 << n) - 1:
                    return steps
                for nei in graph[node]:
                    new_mask = mask | (1 << nei)
                    if (new_mask, nei) not in visited:
                        visited.add((new_mask, nei))
                        q.append((new_mask, nei))
        return steps