#https://leetcode.com/problems/minimum-interval-to-include-each-query/
#You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.
#You are also given an integer array queries. The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
#Return an array containing the answers to the queries.
# 
#Example 1:
#Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
#Output: [3,3,1,4]
#Explanation: The queries are processed as follows:
#- Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
#- Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
#- Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
#- Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
#Example 2:
#Input: intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
#Output: [2,-1,4,6]
#Explanation: The queries are processed as follows:
#- Query = 2: The interval [2,3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
#- Query = 19: None of the intervals contain 19. The answer is -1.
#- Query = 5: The interval [2,5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
#- Query = 22: The interval [20,25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
# 
#Constraints:
#	1 <= intervals.length <= 105
#	1 <= queries.length <= 105
#	intervals[i].length == 2
#	1 <= lefti <= righti <= 107
#	1 <= queries[j] <= 107
class Solution(object):
    def minInterval(self, intervals, queries):
        """
        :type intervals: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """
        import heapq
        from collections import defaultdict

        # Step 1: Sort intervals by their starting point
        intervals.sort(key=lambda x: x[0])
        
        # Step 2: Create a list of queries with their original indices
        queries = sorted((q, i) for i, q in enumerate(queries))
        
        # Step 3: Initialize the result array and a min-heap for intervals
        res = [-1] * len(queries)
        min_heap = []
        
        j = 0    
        n = len(intervals)
        m = len(queries)
        # Step 4: Process each query
        for q, idx in queries:
            # Step 4a: Add all intervals that start before or at the query point to the min-heap
            while j < n and intervals[j][0] <= q:
                # Calculate the size of the interval and push it to the heap
                size = intervals[j][1] - intervals[j][0] + 1
                heapq.heappush(min_heap, (size, intervals[j][1]))
                j += 1

            # Step 4b: Remove all intervals from the heap that end before the query point
            while min_heap and min_heap[0][1] < q:
                heapq.heappop(min_heap)

            # Step 4c: If there are valid intervals in the heap, get the smallest size
            if min_heap:
                res[idx] = min_heap[0][0]

        return res  