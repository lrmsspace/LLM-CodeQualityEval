# You are given a circular array nums and an array queries.
# For each query i, you have to find the following:
# The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
# Return an array answer of the same size as queries, where answer[i] represents the result for query i.
# Example 1:
# Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]
# Output: [2,-1,3]
# Explanation:
# Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
# Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
# Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).
# Example 2:
# Input: nums = [1,2,3,4], queries = [0,1,2,3]
# Output: [-1,-1,-1,-1]
# Explanation:
# Each value in nums is unique, so no index shares the same value as the queried element. This results in -1 for all queries.
# Constraints:
# 1 <= queries.length <= nums.length <= 105
# 1 <= nums[i] <= 106
# 0 <= queries[i] < nums.length

class Solution(object):
    def solveQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[int]
        :rtype: List[int]
        """

        n = len(nums)
        answer = [-1] * len(queries)

        # Create a mapping from value to all its indices
        value_to_indices = {}
        for i in range(n):
            if nums[i] not in value_to_indices:
                value_to_indices[nums[i]] = []
            value_to_indices[nums[i]].append(i)

        # Process each query
        for i, q in enumerate(queries):
            target = nums[q]
            if target in value_to_indices:
                indices = value_to_indices[target]
                # Find the closest index using binary search
                pos = bisect.bisect_left(indices, q)
                # Check the closest indices on both sides
                closest = float('inf')
                if pos < len(indices):
                    closest = min(closest, (indices[pos] - q) % n)
                if pos > 0:
                    closest = min(closest, (q - indices[pos - 1]) % n)
                answer[i] = closest

        return answer