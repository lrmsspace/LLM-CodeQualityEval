#https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/
#There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.
#You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.
#Return true if it is possible to make the degree of each node in the graph even, otherwise return false.
#The degree of a node is the number of edges connected to it.
# 
#Example 1:
#Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
#Output: true
#Explanation: The above diagram shows a valid way of adding an edge.
#Every node in the resulting graph is connected to an even number of edges.
#Example 2:
#Input: n = 4, edges = [[1,2],[3,4]]
#Output: true
#Explanation: The above diagram shows a valid way of adding two edges.
#Example 3:
#Input: n = 4, edges = [[1,2],[1,3],[1,4]]
#Output: false
#Explanation: It is not possible to obtain a valid graph with adding at most 2 edges.
# 
#Constraints:
#	3 <= n <= 105
#	2 <= edges.length <= 105
#	edges[i].length == 2
#	1 <= ai, bi <= n
#	ai != bi
#	There are no repeated edges.
class Solution(object):
    def isPossible(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u-1].append(v-1)
            graph[v-1].append(u-1)
        
        odd = []
        for i in range(n):
            if len(graph[i]) % 2 != 0:
                odd.append(i)
        
        if len(odd) == 0:
            return True
        elif len(odd) == 2:
            u, v = odd
            if v not in graph[u]:
                return True
            for i in range(n):
                if i != u and i != v and v not in graph[i]:
                    return True
        elif len(odd) == 4:
            u, v, x, y = odd
            if v not in graph[u] and x not in graph[y]:
                return True
            if x not in graph[v] and y not in graph[u]:
                return True
            if y not in graph[v] and x not in graph[u]:
                return True
        return False
        