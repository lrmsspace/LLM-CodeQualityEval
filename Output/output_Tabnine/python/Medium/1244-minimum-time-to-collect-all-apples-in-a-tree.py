#https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
#Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.
#The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
# 
#Example 1:
#Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
#Output: 8 
#Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
#Example 2:
#Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
#Output: 6
#Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
#Example 3:
#Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
#Output: 0
# 
#Constraints:
#	1 <= n <= 105
#	edges.length == n - 1
#	edges[i].length == 2
#	0 <= ai < bi <= n - 1
#	hasApple.length == n
class Solution(object):
    def minTime(self, n, edges, hasApple):
        """
        :type n: int
        :type edges: List[List[int]]
        :type hasApple: List[bool]
        :rtype: int
        """
        # Create adjacency list
        adjList = [[] for _ in range(n)]
        for u, v in edges:
            adjList[u].append(v)
            adjList[v].append(u)
        
        # DFS to find the farthest node from each node
        farthestNode = [None] * n
        maxDist = [0] * n
        def dfs(node, parent):
            nonlocal maxDist
            maxDist[node] = 0
            for neighbor in adjList[node]:
                if neighbor!= parent:
                    dfs(neighbor, node)
                    maxDist[node] = max(maxDist[node], maxDist[neighbor] + 1)
        
        dfs(0, None)
        farthestNode[0] = maxDist.index(max(maxDist))
        
        # BFS to find the minimum time to collect all apples
        visited = [False] * n
        minTime = 0
        queue = [farthestNode[0]]
        while queue:
            node = queue.pop(0)
            if visited[node]:
                continue
            visited[node] = True
            if hasApple[node]:
                minTime += 1
            for neighbor in adjList[node]:
                if not visited[neighbor]:
                    queue.append(neighbor)
                    minTime += maxDist[node] - maxDist[neighbor]
                elif hasApple[neighbor]:
                    minTime += maxDist[node] - maxDist[neighbor] + 1
        
        return minTime
        