#https://leetcode.com/problems/subarrays-with-k-different-integers/
#Given an integer array nums and an integer k, return the number of good subarrays of nums.
#A good array is an array where the number of different integers in that array is exactly k.
#	For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
#A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [1,2,1,2,3], k = 2
#Output: 7
#Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
#Example 2:
#Input: nums = [1,2,1,3,4], k = 3
#Output: 3
#Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i], k <= nums.length
class Solution(object):
    def subarraysWithKDistinct(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize two pointers, left and right, to keep track of the current subarray.
        left, right = 0, 0
        
        # Initialize two dictionaries, count and diff, to keep track of the number of different integers in the current subarray.
        count, diff = {}, 0
        
        # Initialize a variable, result, to store the number of good subarrays.
        result = 0
        
        # Iterate through the array using the right pointer.
        while right < len(nums):
            # If the current integer is already in the count dictionary, increment its count.
            if nums[right] in count:
                count[nums[right]] += 1
            # Otherwise, add the current integer to the count dictionary and increment the diff count.
            else:
                count[nums[right]] = 1
                diff += 1
            
            # While the number of different integers in the current subarray is greater than k, move the left pointer to the right until the count of the integer at the left pointer is reduced.
            while diff > k:
                count[nums[left]] -= 1
                # If the count of the integer at the left pointer becomes 0, decrement the diff count.
                if count[nums[left]] == 0:
                    diff -= 1
                # Move the left pointer to the right.
                left += 1
            
            # Add the number of good subarrays formed with exactly k different integers to the result.
            result += right - left + 1
            
            # Move the right pointer to the right.
            right += 1
        
        # Return the result.
        return result
        