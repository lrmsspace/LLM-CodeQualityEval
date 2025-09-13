#https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
#You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
#You are allowed to choose exactly one element from each row to form an array.
#Return the kth smallest array sum among all possible arrays.
# 
#Example 1:
#Input: mat = [[1,3,11],[2,4,6]], k = 5
#Output: 7
#Explanation: Choosing one element from each row, the first k smallest sum are:
#[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.
#Example 2:
#Input: mat = [[1,3,11],[2,4,6]], k = 9
#Output: 17
#Example 3:
#Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
#Output: 9
#Explanation: Choosing one element from each row, the first k smallest sum are:
#[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
# 
#Constraints:
#	m == mat.length
#	n == mat.length[i]
#	1 <= m, n <= 40
#	1 <= mat[i][j] <= 5000
#	1 <= k <= min(200, nm)
#	mat[i] is a non-decreasing array.
class Solution(object):
    def kthSmallest(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: int
        """
        import heapq
        from itertools import combinations

        # Initialize a min-heap
        min_heap = []
        # Push the first row into the heap with its sum and index
        heapq.heappush(min_heap, (sum(mat[0]), 0, [0] * len(mat)))

        # Initialize a set to keep track of visited states
        visited = set()
        visited.add((0,) * len(mat))

        # Iterate k times to find the kth smallest sum
        for _ in range(k):
            current_sum, row_index, indices = heapq.heappop(min_heap)

            # If we reach the last row, return the current sum
            if row_index == len(mat) - 1:
                return current_sum

            # Iterate through each column in the next row
            for j in range(len(mat[row_index + 1])):
                new_indices = indices[:]
                new_indices[row_index + 1] = j
                new_sum = current_sum - mat[row_index][indices[row_index]] + mat[row_index + 1][j]

                # If this state has not been visited yet, push it into the heap
                if tuple(new_indices) not in visited:
                    visited.add(tuple(new_indices))
                    heapq.heappush(min_heap, (new_sum, row_index + 1, new_indices))  
        return -1         