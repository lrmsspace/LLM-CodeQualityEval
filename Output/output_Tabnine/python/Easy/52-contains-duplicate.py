#https://leetcode.com/problems/contains-duplicate/
#Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
# 
#Example 1:
#Input: nums = [1,2,3,1]
#Output: true
#Explanation:
#The element 1 occurs at the indices 0 and 3.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: false
#Explanation:
#All elements are distinct.
#Example 3:
#Input: nums = [1,1,1,3,3,4,3,2,4,2]
#Output: true
# 
#Constraints:
#	1 <= nums.length <= 105
#	-109 <= nums[i] <= 109
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # Create a dictionary to store the frequency of each number
        freq_dict = {}
        
        # Iterate through the list and update the frequency in the dictionary
        for num in nums:
            if num in freq_dict:
                freq_dict[num] += 1
            else:
                freq_dict[num] = 1
        
        # Iterate through the dictionary and check if any frequency is greater than 1
        for freq in freq_dict.values():
            if freq > 1:
                return True
        
        # If no frequency is greater than 1, return False
        return False
        