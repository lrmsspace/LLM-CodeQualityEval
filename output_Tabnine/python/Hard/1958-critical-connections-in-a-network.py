#https://leetcode.com/problems/critical-connections-in-a-network/
#There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
#A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
#Return all critical connections in the network in any order.
# 
#Example 1:
#Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
#Output: [[1,3]]
#Explanation: [[3,1]] is also accepted.
#Example 2:
#Input: n = 2, connections = [[0,1]]
#Output: [[0,1]]
# 
#Constraints:
#	2 <= n <= 105
#	n - 1 <= connections.length <= 105
#	0 <= ai, bi <= n - 1
#	ai != bi
#	There are no repeated connections.
class Solution(object):
    def criticalConnections(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: List[List[int]]
        """
        graph = [[] for _ in range(n)]
        for u, v in connections:
            graph[u].append(v)
            graph[v].append(u)
        
        visited = [False] * n
        low = [float('inf')] * n
        parent = [-1] * n
        result = []
        
        def dfs(node, parent):
            visited[node] = True
            low[node] = parent
            min_low = low[node]
            
            for neighbor in graph[node]:
                if neighbor == parent:
                    continue
                
                if not visited[neighbor]:
                    dfs(neighbor, node)
                    min_low = min(min_low, low[neighbor])
                
                if min_low > low[node]:
                    result.append([min(node, neighbor), max(node, neighbor)])
            
            low[node] = min_low
        
        dfs(0, -1)
        
        return result
        