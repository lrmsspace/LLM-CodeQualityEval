#https://leetcode.com/problems/minimum-incompatibility/
#You are given an integer array nums​​​ and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.
#A subset's incompatibility is the difference between the maximum and minimum elements in that array.
#Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.
#A subset is a group integers that appear in the array with no particular order.
# 
#Example 1:
#Input: nums = [1,2,1,4], k = 2
#Output: 4
#Explanation: The optimal distribution of subsets is [1,2] and [1,4].
#The incompatibility is (2-1) + (4-1) = 4.
#Note that [1,1] and [2,4] would result in a smaller sum, but the first subset contains 2 equal elements.
#Example 2:
#Input: nums = [6,3,8,1,3,1,2,2], k = 4
#Output: 6
#Explanation: The optimal distribution of subsets is [1,2], [2,3], [6,8], and [1,3].
#The incompatibility is (2-1) + (3-2) + (8-6) + (3-1) = 6.
#Example 3:
#Input: nums = [5,3,3,6,3,3], k = 3
#Output: -1
#Explanation: It is impossible to distribute nums into 3 subsets where no two elements are equal in the same subset.
# 
#Constraints:
#	1 <= k <= nums.length <= 16
#	nums.length is divisible by k
#	1 <= nums[i] <= nums.length
class Solution(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        from itertools import combinations
        from collections import defaultdict

        n = len(nums)
        if n % k != 0:
            return -1

        m = n // k
        nums.sort()
        dp = [float('inf')] * (1 << n)
        dp[0] = 0

        for mask in range(1 << n):
            if dp[mask] == float('inf'):
                continue
            used = [False] * 17
            for i in range(n):
                if mask & (1 << i) == 0:
                    used[nums[i]] = True

            for comb in combinations(range(n), m):
                new_mask = mask
                min_num, max_num = float('inf'), float('-inf')
                for i in comb:
                    new_mask |= (1 << i)
                    min_num = min(min_num, nums[i])
                    max_num = max(max_num, nums[i])

                if new_mask != mask and all(not used[nums[i]] for i in comb):
                    dp[new_mask] = min(dp[new_mask], dp[mask] + max_num - min_num)

        return dp[(1 << n) - 1] if dp[(1 << n) - 1] != float('inf') else -1        