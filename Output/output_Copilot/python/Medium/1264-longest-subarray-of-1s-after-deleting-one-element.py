#https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
#Given a binary array nums, you should delete one element from it.
#Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
# 
#Example 1:
#Input: nums = [1,1,0,1]
#Output: 3
#Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
#Example 2:
#Input: nums = [0,1,1,1,0,1,1,0,1]
#Output: 5
#Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
#Example 3:
#Input: nums = [1,1,1]
#Output: 2
#Explanation: You must delete one element.
# 
#Constraints:
#	1 <= nums.length <= 105
#	nums[i] is either 0 or 1.
class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = 0
        max_length = 0
        zero_count = 0
        
        while right < len(nums):
            if nums[right] == 0:
                zero_count += 1
            
            while zero_count > 1:
                if nums[left] == 0:
                    zero_count -= 1
                left += 1
            
            max_length = max(max_length, right - left)
            right += 1
        
        return max_length        