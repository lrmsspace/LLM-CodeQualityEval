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
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]
        ans = 0
        for i in range(1, n):
            left_sum = prefix_sum[i]
            j = i + 1
            k = n - 1
            while j < k:
                mid_sum = prefix_sum[j] - left_sum
                right_sum = prefix_sum[k] - prefix_sum[j]
                if left_sum <= mid_sum and mid_sum <= right_sum:
                    ans += 1
                if left_sum > mid_sum:
                    j += 1
                elif mid_sum > right_sum:
                    k -= 1
                else:
                    break
        return ans % (10 ** 9 + 7)