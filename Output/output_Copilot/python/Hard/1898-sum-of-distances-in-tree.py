#https://leetcode.com/problems/sum-of-distances-in-tree/
#There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
#You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
#Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
# 
#Example 1:
#Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
#Output: [8,12,6,10,10,10]
#Explanation: The tree is shown above.
#We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
#equals 1 + 1 + 2 + 2 + 2 = 8.
#Hence, answer[0] = 8, and so on.
#Example 2:
#Input: n = 1, edges = []
#Output: [0]
#Example 3:
#Input: n = 2, edges = [[1,0]]
#Output: [1,1]
# 
#Constraints:
#	1 <= n <= 3 * 104
#	edges.length == n - 1
#	edges[i].length == 2
#	0 <= ai, bi < n
#	ai != bi
#	The given input represents a valid tree.
class Solution(object):
    def sumOfDistancesInTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        from collections import defaultdict

        # Step 1: Build the tree using an adjacency list
        tree = defaultdict(list)
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        # Step 2: Initialize variables
        ans = [0] * n   
        count = [1] * n
        visited = [False] * n
        visited[0] = True
        stack = [0]
        parent = [-1] * n
        # Step 3: Post-order DFS to calculate initial distances and counts
        # This DFS calculates the distance from the root (node 0) to all other nodes
        while stack:
            node = stack.pop()
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    parent[neighbor] = node
                    stack.append(neighbor)
                    # Count the number of nodes in the subtree rooted at neighbor
                    count[node] += count[neighbor]
                    # Calculate the distance from node to neighbor
                    ans[node] += ans[neighbor] + count[neighbor]
        # Step 4: Pre-order DFS to calculate distances for all nodes
        visited = [False] * n
        visited[0] = True
        stack = [0]
        # This DFS calculates the distance for all nodes based on the root's distance
        # and the counts of their subtrees
        # The distance from the parent to the child is adjusted based on the number of nodes in the subtree
        while stack:
            node = stack.pop()
            for neighbor in tree[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    # Calculate the distance for the neighbor based on the parent's distance
                    ans[neighbor] = ans[node] - count[neighbor] + (n - count[neighbor])
                    stack.append(neighbor)
        return ans     