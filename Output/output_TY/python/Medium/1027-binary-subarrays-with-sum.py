#https://leetcode.com/problems/binary-subarrays-with-sum/
#Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
#A subarray is a contiguous part of the array.
# 
#Example 1:
#Input: nums = [1,0,1,0,1], goal = 2
#Output: 4
#Explanation: The 4 subarrays are bolded and underlined below:
#[1,0,1,0,1]
#[1,0,1,0,1]
#[1,0,1,0,1]
#[1,0,1,0,1]
#Example 2:
#Input: nums = [0,0,0,0,0], goal = 0
#Output: 15
# 
#Constraints:
#	1 <= nums.length <= 3 * 104
#	nums[i] is either 0 or 1.
#	0 <= goal <= nums.length
class Solution(object):
    def numSubarraysWithSum(self, nums, goal):
        """
        :type nums: List[int]
        :type goal: int
        :rtype: int
        """
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1]
        ans = 0
        for i in range(n + 1):
            for j in range(i + 1, n + 1):
                if prefix_sum[j] - prefix_sum[i] == goal:
                    ans += 1
        return ans