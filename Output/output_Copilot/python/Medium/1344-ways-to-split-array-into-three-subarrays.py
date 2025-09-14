#https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
#A split of an integer array is good if:
#	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
#	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
#Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
# 
#Example 1:
#Input: nums = [1,1,1]
#Output: 1
#Explanation: The only good way to split nums is [1] [1] [1].
#Example 2:
#Input: nums = [1,2,2,2,5,0]
#Output: 3
#Explanation: There are three good ways of splitting nums:
#[1] [2] [2,2,5,0]
#[1] [2,2] [2,5,0]
#[1,2] [2,2] [5,0]
#Example 3:
#Input: nums = [3,2,1]
#Output: 0
#Explanation: There is no good way to split nums.
# 
#Constraints:
#	3 <= nums.length <= 105
#	0 <= nums[i] <= 104
class Solution(object):
    def waysToSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(n):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]

        mod = 10**9 + 7
        count = 0
        j = k = 0

        for i in range(1, n - 1):
            while j < i and prefix_sum[j + 1] - prefix_sum[0] < prefix_sum[i + 1] - prefix_sum[j + 1]:
                j += 1
            while k < n - 1 and prefix_sum[k + 1] - prefix_sum[i + 1] <= prefix_sum[n] - prefix_sum[k + 1]:
                k += 1
            count += max(0, k - j)

        return count % mod        