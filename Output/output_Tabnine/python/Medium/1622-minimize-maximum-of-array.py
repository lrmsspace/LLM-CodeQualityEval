#https://leetcode.com/problems/minimize-maximum-of-array/
#You are given a 0-indexed array nums comprising of n non-negative integers.
#In one operation, you must:
#	Choose an integer i such that 1 <= i < n and nums[i] > 0.
#	Decrease nums[i] by 1.
#	Increase nums[i - 1] by 1.
#Return the minimum possible value of the maximum integer of nums after performing any number of operations.
# 
#Example 1:
#Input: nums = [3,7,1,6]
#Output: 5
#Explanation:
#One set of optimal operations is as follows:
#1. Choose i = 1, and nums becomes [4,6,1,6].
#2. Choose i = 3, and nums becomes [4,6,2,5].
#3. Choose i = 1, and nums becomes [5,5,2,5].
#The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
#Therefore, we return 5.
#Example 2:
#Input: nums = [10,1]
#Output: 10
#Explanation:
#It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.
# 
#Constraints:
#	n == nums.length
#	2 <= n <= 105
#	0 <= nums[i] <= 109
class Solution(object):
    def minimizeArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Sort the array in descending order
        nums.sort(reverse=True)
        
        # Iterate through the array and perform operations
        for i in range(len(nums) - 1):
            # If nums[i] is greater than nums[i + 1], decrease nums[i] and increase nums[i + 1]
            if nums[i] > nums[i + 1]:
                nums[i] -= 1
                nums[i + 1] += 1
        
        # Return the maximum integer of the array
        return nums[0]
        