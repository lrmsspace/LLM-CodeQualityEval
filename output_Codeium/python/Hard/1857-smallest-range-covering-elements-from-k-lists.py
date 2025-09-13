#https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
#You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
#We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
# 
#Example 1:
#Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
#Output: [20,24]
#Explanation: 
#List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
#List 2: [0, 9, 12, 20], 20 is in range [20,24].
#List 3: [5, 18, 22, 30], 22 is in range [20,24].
#Example 2:
#Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
#Output: [1,1]
# 
#Constraints:
#	nums.length == k
#	1 <= k <= 3500
#	1 <= nums[i].length <= 50
#	-105 <= nums[i][j] <= 105
#	nums[i] is sorted in non-decreasing order.
class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        import heapq

        min_heap = []
        max_value = float('-inf')

        # Initialize the heap with the first element from each list and track the max value
        for i in range(len(nums)):
            heapq.heappush(min_heap, (nums[i][0], i, 0))
            max_value = max(max_value, nums[i][0])

        # Initialize the range
        smallest_range = [float('-inf'), float('inf')]

        while min_heap:
            min_value, list_idx, element_idx = heapq.heappop(min_heap)

            # Update the smallest range if the current range is smaller
            if max_value - min_value < smallest_range[1] - smallest_range[0]:
                smallest_range = [min_value, max_value]

            # If there's a next element in the list, add it to the heap
            if element_idx + 1 < len(nums[list_idx]):
                next_value = nums[list_idx][element_idx + 1]
                heapq.heappush(min_heap, (next_value, list_idx, element_idx + 1))
                max_value = max(max_value, next_value)
            else:
                break

        return smallest_range

