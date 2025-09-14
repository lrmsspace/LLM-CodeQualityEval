#https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/
#You are given an integer array nums. The value of this array is defined as the sum of |nums[i] - nums[i + 1]| for all 0 <= i < nums.length - 1.
#You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.
#Find maximum possible value of the final array.
# 
#Example 1:
#Input: nums = [2,3,1,5,4]
#Output: 10
#Explanation: By reversing the subarray [3,1,5] the array becomes [2,5,1,3,4] whose value is 10.
#Example 2:
#Input: nums = [2,4,9,24,2,1,10]
#Output: 68
# 
#Constraints:
#	2 <= nums.length <= 3 * 104
#	-105 <= nums[i] <= 105
#	The answer is guaranteed to fit in a 32-bit integer.
class Solution(object):
    def maxValueAfterReverse(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        base = sum(abs(nums[i] - nums[i + 1]) for i in range(n - 1))
        maxi = 0
        for i in range(n - 1):
            for j in range(i + 1, n):
                if i > 0:
                    maxi = max(maxi, -abs(nums[i - 1] - nums[i]) - abs(nums[j] - nums[i]) + abs(nums[j] - nums[i - 1]) + abs(nums[i + 1] - nums[i]))
                if j < n - 1:
                    maxi = max(maxi, -abs(nums[i] - nums[j]) - abs(nums[j + 1] - nums[j]) + abs(nums[j + 1] - nums[i]) + abs(nums[j + 1] - nums[i]))
        return base + maxi
        