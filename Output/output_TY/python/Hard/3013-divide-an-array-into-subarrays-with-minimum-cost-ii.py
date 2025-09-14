# You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.
# The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
# You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.
# Return the minimum possible sum of the cost of these subarrays.
# Example 1:
# Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
# Output: 5
# Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
# It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
# Example 2:
# Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
# Output: 15
# Explanation: The best possible way to divide nums into 4 subarrays is: [10], [1], [2], and [2,2,1]. This choice is valid because ik-1 - i1 is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
# The division [10], [1], [2,2,2], and [1] is not valid, because the difference between ik-1 and i1 is 5 - 1 = 4, which is greater than dist.
# It can be shown that there is no possible way to divide nums into 4 subarrays at a cost lower than 15.
# Example 3:
# Input: nums = [10,8,18,9], k = 3, dist = 1
# Output: 36
# Explanation: The best possible way to divide nums into 4 subarrays is: [10], [8], and [18,9]. This choice is valid because ik-1 - i1 is 2 - 1 = 1 which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which is 10 + 8 + 18 = 36.
# The division [10], [8,18], and [9] is not valid, because the difference between ik-1 and i1 is 3 - 1 = 2, which is greater than dist.
# It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 36.
# Constraints:
# 3 <= n <= 105
# 1 <= nums[i] <= 109
# 3 <= k <= n
# k - 2 <= dist <= n - 2

from heapq import heappush, heappop
from collections import defaultdict

class Solution(object):
    def minimumCost(self, nums, k, dist):
        """
        :type nums: List[int]
        n = len(nums)
        :type k: int
        :type dist: int
        :rtype: int
        """
        n = len(nums)
        res = float('inf')
        heap = []
        sum_heap = 0
        removed = defaultdict(int)

        left = 1
        for right in range(1, n):
            heappush(heap, nums[right])
            sum_heap += nums[right]

            while len(heap) > k - 1:
                removed_val = heap.pop()
                sum_heap -= removed_val

            while right - left >= dist:
                removed[nums[left]] += 1
                if heap and heap[0] == nums[left]:
                    sum_heap -= heappop(heap)
                left += 1

                while heap and removed[heap[0]] > 0:
                    removed[heap[0]] -= 1
                    sum_heap -= heap[0]
                    heappop(heap)

            if right - left + 1 <= dist and len(heap) == k - 1:
                total_cost = nums[0] + sum_heap
                res = min(res, total_cost)

        return res