#https://leetcode.com/problems/contiguous-array/
#Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
# 
#Example 1:
#Input: nums = [0,1]
#Output: 2
#Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
#Example 2:
#Input: nums = [0,1,0]
#Output: 2
#Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
# 
#Constraints:
#	1 <= nums.length <= 105
#	nums[i] is either 0 or 1.
class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize a dictionary to store the cumulative sum and its corresponding index
        # {sum: index}
        sum_dict = {0: -1}
        
        max_length = 0
        current_sum = 0
        
        for i, num in enumerate(nums):
            # If the current number is 0, its value in the dictionary will be negative
            current_sum += -1 if num == 0 else 1
            
            # If the current sum is already in the dictionary, update the max length
            if current_sum in sum_dict:
                max_length = max(max_length, i - sum_dict[current_sum])
            # If the current sum is not in the dictionary, add it to the dictionary
            else:
                sum_dict[current_sum] = i
        
        return max_length
        