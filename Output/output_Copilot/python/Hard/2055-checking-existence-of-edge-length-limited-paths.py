#https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
#An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.
#Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .
#Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.
# 
#Example 1:
#Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
#Output: [false,true]
#Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
#For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
#For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
#Example 2:
#Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
#Output: [true,false]
#Explanation: The above figure shows the given graph.
# 
#Constraints:
#	2 <= n <= 105
#	1 <= edgeList.length, queries.length <= 105
#	edgeList[i].length == 3
#	queries[j].length == 3
#	0 <= ui, vi, pj, qj <= n - 1
#	ui != vi
#	pj != qj
#	1 <= disi, limitj <= 109
#	There may be multiple edges between two nodes.
class Solution(object):
    def distanceLimitedPathsExist(self, n, edgeList, queries):
        """
        :type n: int
        :type edgeList: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        # Sort the edges by their distance in ascending order
        edgeList.sort(key=lambda x: x[2])
        
        # Sort the queries by their limit in ascending order, while keeping track of their original indices
        indexed_queries = sorted(enumerate(queries), key=lambda x: x[1][2])
        
        # Initialize the Union-Find data structure
        parent = list(range(n))
        rank = [1] * n
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  
            return parent[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1

        # Initialize the result array with False values
        # result = [False] * len(queries)
        result = [False] * len(queries)
        edge_index = 0
        # Iterate through the sorted queries and edges
        # for i, (original_index, (p, q, limit)) in enumerate(indexed_queries):
        for original_index, (p, q, limit) in indexed_queries:
            # Union edges with distance less than the current query limit
            while edge_index < len(edgeList) and edgeList[edge_index][2] < limit:
                union(edgeList[edge_index][0], edgeList[edge_index][1])
                edge_index += 1
            # Check if p and q are in the same connected component
            result[original_index] = find(p) == find(q)
        return result         