#https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
#Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
# 
#Example 1:
#Input: nums = [1,0,0,0,1,0,0,1], k = 2
#Output: true
#Explanation: Each of the 1s are at least 2 places away from each other.
#Example 2:
#Input: nums = [1,0,0,1,0,1], k = 2
#Output: false
#Explanation: The second 1 and third 1 are only one apart from each other.
# 
#Constraints:
#	1 <= nums.length <= 105
#	0 <= k <= nums.length
#	nums[i] is 0 or 1
class Solution(object):
    def kLengthApart(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        # Initialize the first index to -1 and the current index to 0
        first_index = -1
        current_index = 0
        
        # Iterate through the nums array
        while current_index < len(nums):
            # If the current number is 1, update the first index
            if nums[current_index] == 1:
                first_index = current_index
            
            # If the current number is 0 and the first index is not -1, check if the distance is at least k
            elif first_index!= -1 and current_index - first_index >= k:
                # If the distance is at least k, move the first index to the current index
                first_index = current_index
            
            # Move to the next index
            current_index += 1
        
        # If all 1's are at least k places away from each other, return True
        return first_index == -1
        