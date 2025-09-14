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
        # 统计前缀和出现的次数
        prefix_sum_count = {0: 1}
        prefix_sum = 0
        count = 0
        
        for num in nums:
            prefix_sum += num
            # 如果当前前缀和减去目标值的前缀和存在，则说明有符合条件的子数组
            if prefix_sum - goal in prefix_sum_count:
                count += prefix_sum_count[prefix_sum - goal]
            
            # 更新前缀和出现的次数
            if prefix_sum in prefix_sum_count:
                prefix_sum_count[prefix_sum] += 1
            else:
                prefix_sum_count[prefix_sum] = 1
        
        return count        