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
        for i in range(1, n):
            nums[i] += nums[i-1]
        res = 0
        for i in range(1, n-1):
            l = bisect.bisect_left(nums, 2*nums[i-1], i)
            r = bisect.bisect_right(nums, (nums[-1] + nums[i]) // 2, l)
            res += max(0, r-l)
        return res % (10**9 + 7)

        