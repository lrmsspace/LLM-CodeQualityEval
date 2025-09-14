#https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
#Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
#Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
# 
#Example 1:
#Input: nums = [1,2,1,2,6,7,5,1], k = 2
#Output: [0,3,5]
#Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
#We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
#Example 2:
#Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
#Output: [0,2,4]
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i] < 216
#	1 <= k <= floor(nums.length / 3)
class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        sums = [0] * (n - k + 1)
        for i in range(n - k + 1):
            sums[i] = sum(nums[i:i+k])
        left = [0] * (n - k + 1)
        right = [0] * (n - k + 1)
        best = 0
        for i in range(n - k + 1):
            if sums[i] > sums[best]:
                best = i
            left[i] = best
        best = n - k
        for i in range(n - k, -1, -1):
            if sums[i] >= sums[best]:
                best = i
            right[i] = best
        ans = None
        for j in range(k, n - 2 * k + 1):
            i, k = left[j - k], right[j + k]
            if ans is None or (sums[i] + sums[j] + sums[k] > sums[ans[0]] + sums[ans[1]] + sums[ans[2]]):
                ans = (i, j, k)
        return ans

        