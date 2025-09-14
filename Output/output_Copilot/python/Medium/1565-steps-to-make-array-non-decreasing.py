#https://leetcode.com/problems/steps-to-make-array-non-decreasing/
#You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.
#Return the number of steps performed until nums becomes a non-decreasing array.
# 
#Example 1:
#Input: nums = [5,3,4,4,7,3,6,11,8,5,11]
#Output: 3
#Explanation: The following are the steps performed:
#- Step 1: [5,3,4,4,7,3,6,11,8,5,11] becomes [5,4,4,7,6,11,11]
#- Step 2: [5,4,4,7,6,11,11] becomes [5,4,7,11,11]
#- Step 3: [5,4,7,11,11] becomes [5,7,11,11]
#[5,7,11,11] is a non-decreasing array. Therefore, we return 3.
#Example 2:
#Input: nums = [4,5,7,7,13]
#Output: 0
#Explanation: nums is already a non-decreasing array. Therefore, we return 0.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 109
class Solution(object):
    def totalSteps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stack = []
        dp = [0] * len(nums)
        max_steps = 0

        for i in range(len(nums)):
            steps = 0
            while stack and nums[stack[-1]] <= nums[i]:
                steps = max(steps, dp[stack.pop()])
            if stack:
                dp[i] = steps + 1
            stack.append(i)
            max_steps = max(max_steps, dp[i])

        return max_steps        