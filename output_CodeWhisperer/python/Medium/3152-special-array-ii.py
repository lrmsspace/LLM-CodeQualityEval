# An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
# You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that subarray nums[fromi..toi] is special or not.
# Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
# Example 1:
# Input: nums = [3,4,1,2,6], queries = [[0,4]]
# Output: [false]
# Explanation:
# The subarray is [3,4,1,2,6]. 2 and 6 are both even.
# Example 2:
# Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
# Output: [false,true]
# Explanation:
# The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
# The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 105
# 1 <= queries.length <= 105
# queries[i].length == 2
# 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1

class Solution(object):
    def isArraySpecial(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        n = len(nums)
        parity = [nums[i] % 2 for i in range(n)]
        prefix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + (parity[i - 1] != parity[i - 2] if i > 1 else True)

        result = []
        for query in queries:
            start, end = query
            if prefix_sum[end + 1] - prefix_sum[start] == end - start + 1:
                result.append(True)
            else:
                result.append(False)
        return result        