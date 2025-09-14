# You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
# Each queries[i] represents the following action on nums:
# Decrement the value at each index in the range [li, ri] in nums by at most 1.
# The amount by which the value is decremented can be chosen independently for each index.
# A Zero Array is an array with all its elements equal to 0.
# Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
# Example 1:
# Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
# Output: 1
# Explanation:
# After removing queries[2], nums can still be converted to a zero array.
# Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
# Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
# Example 2:
# Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]
# Output: 2
# Explanation:
# We can remove queries[2] and queries[3].
# Example 3:
# Input: nums = [1,2,3,4], queries = [[0,3]]
# Output: -1
# Explanation:
# nums cannot be converted to a zero array even after using all the queries.
# Constraints:
# 1 <= nums.length <= 105
# 0 <= nums[i] <= 105
# 1 <= queries.length <= 105
# queries[i].length == 2
# 0 <= li <= ri < nums.length

class Solution(object):
    def maxRemoval(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        n = len(nums)
        m = len(queries)
        prefix_sum = [0] * (n + 1)

        # Calculate the total decrement needed for each index
        for l, r in queries:
            prefix_sum[l] += 1
            if r + 1 < n:
                prefix_sum[r + 1] -= 1

        # Compute the actual decrements at each index
        for i in range(1, n):
            prefix_sum[i] += prefix_sum[i - 1]

        # Check if we can convert nums to a zero array
        for i in range(n):
            if nums[i] > prefix_sum[i]:
                return -1

        # Binary search to find the maximum number of removable queries
        left, right = 0, m
        while left < right:
            mid = (left + right + 1) // 2
            temp_prefix = [0] * (n + 1)

            # Apply the first mid queries
            for i in range(mid):
                l, r = queries[i]
                temp_prefix[l] += 1
                if r + 1 < n:
                    temp_prefix[r + 1] -= 1

            # Compute the decrements with these queries
            for i in range(1, n):
                temp_prefix[i] += temp_prefix[i - 1]

            # Check if we can still convert nums to a zero array
            can_convert = True
            for i in range(n):
                if nums[i] > temp_prefix[i]:
                    can_convert = False
                    break

            if can_convert:
                left = mid    
            else:
                right = mid - 1

        return left