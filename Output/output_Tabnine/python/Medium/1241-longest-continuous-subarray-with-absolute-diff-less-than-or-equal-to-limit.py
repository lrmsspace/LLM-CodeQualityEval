#https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
#Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.
# 
#Example 1:
#Input: nums = [8,2,4,7], limit = 4
#Output: 2 
#Explanation: All subarrays are: 
#[8] with maximum absolute diff |8-8| = 0 <= 4.
#[8,2] with maximum absolute diff |8-2| = 6 > 4. 
#[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
#[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
#[2] with maximum absolute diff |2-2| = 0 <= 4.
#[2,4] with maximum absolute diff |2-4| = 2 <= 4.
#[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
#[4] with maximum absolute diff |4-4| = 0 <= 4.
#[4,7] with maximum absolute diff |4-7| = 3 <= 4.
#[7] with maximum absolute diff |7-7| = 0 <= 4. 
#Therefore, the size of the longest subarray is 2.
#Example 2:
#Input: nums = [10,1,2,4,7,2], limit = 5
#Output: 4 
#Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
#Example 3:
#Input: nums = [4,2,2,2,4,4,2,2], limit = 0
#Output: 3
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 109
#	0 <= limit <= 109
class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        # Initialize variables
        left, right, max_length = 0, 0, 0
        min_map, max_map = {}, {}
        
        # Iterate through the array
        while right < len(nums):
            # Update min and max maps
            if nums[right] not in min_map:
                min_map[nums[right]] = right
            if nums[right] not in max_map:
                max_map[nums[right]] = right
            
            # Calculate the absolute difference
            diff = max(nums[right] - min_map[nums[right]], max_map[nums[right]] - min_map[nums[right]])
            
            # Update max_length if necessary
            if diff <= limit:
                max_length = max(max_length, right - left + 1)
            else:
                # Move the left pointer to the rightmost position of the current window
                while diff > limit:
                    left_val = nums[left]
                    if left_val in min_map:
                        del min_map[left_val]
                    if left_val in max_map:
                        del max_map[left_val]
            
                    left += 1
                    # Calculate the new absolute difference
                    if left < right:
                        diff = max(nums[right] - min_map[nums[right]], max_map[nums[right]] - min_map[nums[right]])
            
            # Update max_length if necessary
            if diff <= limit:
                max_length = max(max_length, right - left + 1)
            
            right += 1
        
        return max_length
        