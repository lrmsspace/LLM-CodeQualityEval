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
        # Build adjacency list
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
        
        # Initialize count array and visited sets
        # count[i][c] represents max count of color c in paths ending at node i
        count = [[0] * 26 for _ in range(n)]
        visited = set()        # For cycle detection
        in_stack = set()      # For current DFS path
        
        def dfs(node):
            if node in in_stack:  # Cycle detected
                return False
            if node in visited:   # Already processed
                return True
                
            in_stack.add(node)
            visited.add(node)
            
            # Get color index for current node
            color = ord(colors[node]) - ord('a')
            
            # Process all neighbors
            for nei in graph[node]:
                if not dfs(nei):
                    return False
                # Update counts for all colors
                for c in range(26):
                    count[node][c] = max(count[node][c], count[nei][c])
            
            # Add current node's color
            count[node][color] += 1
            in_stack.remove(node)
            return True
        
        # Process all nodes
        max_count = 0
        for node in range(n):
            if not dfs(node):
                return -1
            max_count = max(max_count, max(count[node]))
        
        return max_count
    