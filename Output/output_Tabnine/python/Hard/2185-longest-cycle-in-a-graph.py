#https://leetcode.com/problems/longest-cycle-in-a-graph/
#You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
#The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.
#Return the length of the longest cycle in the graph. If no cycle exists, return -1.
#A cycle is a path that starts and ends at the same node.
# 
#Example 1:
#Input: edges = [3,3,4,2,3]
#Output: 3
#Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
#The length of this cycle is 3, so 3 is returned.
#Example 2:
#Input: edges = [2,-1,3,1]
#Output: -1
#Explanation: There are no cycles in this graph.
# 
#Constraints:
#	n == edges.length
#	2 <= n <= 105
#	-1 <= edges[i] < n
#	edges[i] != i
class Solution(object):
    def longestCycle(self, edges):
        """
        :type edges: List[int]
        :rtype: int
        """
        # Create an adjacency list
        n = len(edges)
        adj_list = [[] for _ in range(n)]
        for i, j in enumerate(edges):
            if j!= -1:
                adj_list[i].append(j)
        
        # Initialize the visited array
        visited = [False] * n
        
        # Initialize the cycle length and longest cycle start index
        cycle_len = -1
        start_index = -1
        
        # Perform DFS to find the longest cycle
        for i in range(n):
            if not visited[i]:
                if self.dfs(i, -1, edges, visited, adj_list, cycle_len, start_index):
                    return cycle_len
        
        return -1
        