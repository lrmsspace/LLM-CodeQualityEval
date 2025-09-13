#https://leetcode.com/problems/shortest-path-with-alternating-colors/
#You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
#You are given two arrays redEdges and blueEdges where:
#	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
#	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
#Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
# 
#Example 1:
#Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
#Output: [0,1,-1]
#Example 2:
#Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
#Output: [0,1,-1]
# 
#Constraints:
#	1 <= n <= 100
#	0 <= redEdges.length, blueEdges.length <= 400
#	redEdges[i].length == blueEdges[j].length == 2
#	0 <= ai, bi, uj, vj < n
class Solution(object):
    def shortestAlternatingPaths(self, n, redEdges, blueEdges):
        """
        :type n: int
        :type redEdges: List[List[int]]
        :type blueEdges: List[List[int]]
        :rtype: List[int]
        """
        # 1. 使用 BFS 遍历图，记录每个节点的最短路径长度
        # 2. 使用队列存储当前节点和当前颜色
        # 3. 使用 visited 数组记录每个节点的访问状态
        # 4. 时间复杂度 O(n + m)，空间复杂度 O(n + m)
        from collections import deque, defaultdict
        
        graph = defaultdict(list)
        for u, v in redEdges:
            graph[u].append((v, 0))
        for u, v in blueEdges:
            graph[u].append((v, 1))
        
        visited = [[False, False] for _ in range(n)]
        visited[0][0] = True
        visited[0][1] = True
        queue = deque([(0, 0), (0, 1)])
        distance = [float('inf')] * n
        distance[0] = 0
        level = 0
        while queue:
            for _ in range(len(queue)):
                node, color = queue.popleft()
                for neighbor, next_color in graph[node]:
                    if not visited[neighbor][next_color]:
                        visited[neighbor][next_color] = True
                        distance[neighbor] = min(distance[neighbor], level + 1)
                        queue.append((neighbor, next_color))
            level += 1
        for i in range(n):
            if distance[i] == float('inf'):
                distance[i] = -1
        return distance