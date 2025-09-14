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
        # Create adjacency list
        adj_list = [[] for _ in range(n)]
        for u, v, w in edgeList:
            adj_list[u].append((v, w))
            adj_list[v].append((u, w))
        
        # Sort edges by distance
        edgeList.sort(key=lambda x: x[2])
        
        # Create a BIT (Fenwick Tree) for efficient range updates
        bit = [0] * (n + 1)
        
        def update(i, delta):
            while i <= n:
                bit[i] += delta
                i += i & -i
        
        def query(i):
            res = 0
            while i > 0:
                res += bit[i]
                i -= i & -i
            return res
        
        # Initialize answer array
        answer = []
        
        # Process queries
        for p, q, limit in queries:
            # Find the minimum distance among all edges that connects p and q
            min_distance = float('inf')
            for u, v, w in edgeList:
                if u == p or v == p:
                    if w < min_distance:
                        min_distance = w
            
            # If there is no path or the minimum distance is greater than limit, return false
            if min_distance == float('inf') or min_distance > limit:
                answer.append(False)
                continue
            
            # Count the number of edges with distance less than or equal to limit
            count = 0
            for u, v, w in edgeList:
                if u == p or v == p:
                    if w <= limit:
                        count += 1
            
            # Update the BIT for each edge with distance less than or equal to limit
            for u, v, w in edgeList:
                if u == p or v == p:
                    if w <= limit:
                        update(v + 1, 1)
        
        # Query the BIT for each query
        for p, q, limit in queries:
            answer.append(query(q + 1) - query(p))
        
        return answer
        