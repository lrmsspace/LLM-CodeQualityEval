#https://leetcode.com/problems/longest-consecutive-sequence/
#Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
#You must write an algorithm that runs in O(n) time.
# 
#Example 1:
#Input: nums = [100,4,200,1,3,2]
#Output: 4
#Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
#Example 2:
#Input: nums = [0,3,7,2,5,8,4,6,0,1]
#Output: 9
# 
#Constraints:
#	0 <= nums.length <= 105
#	-109 <= nums[i] <= 109
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Create a set for the given array
        num_set = set(nums)
        
        # Initialize the maximum length of consecutive elements sequence
        max_length = 0
        
        # Iterate through the set
        for num in num_set:
            # If the current number is not in the set, check if it is part of a consecutive sequence
            if num - 1 not in num_set:
                current_num = num
                current_length = 1
                
                # Continue to check if the next numbers are consecutive
                while current_num + 1 in num_set:
                    current_num += 1
                    current_length += 1
                
                # Update the maximum length of consecutive elements sequence
                max_length = max(max_length, current_length)
        
        return max_length
        