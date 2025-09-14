#https://leetcode.com/problems/count-subarrays-with-median-k/
#You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
#Return the number of non-empty subarrays in nums that have a median equal to k.
#Note:
#	The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
#	
#		For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
#	
#	
#	A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [3,2,1,4,5], k = 4
#Output: 3
#Explanation: The subarrays that have a median equal to 4 are: [4], [4,5] and [1,4,5].
#Example 2:
#Input: nums = [2,3,1], k = 3
#Output: 1
#Explanation: [3] is the only subarray that has a median equal to 3.
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 105
#	1 <= nums[i], k <= n
#	The integers in nums are distinct.
class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Create a prefix sum array
        prefix_sum = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
        
        # Initialize a dictionary to store the count of each prefix sum
        count = {}
        
        # Initialize the result count
        result = 0
        
        # Iterate through the prefix sums
        for prefix in prefix_sum:
            # Calculate the difference between the prefix sum and the target median
            diff = k - prefix
            
            # Check if the difference exists in the count dictionary
            if diff in count:
                # Add the count of the difference to the result count
                result += count[diff]
            
            # Update the count of the current prefix sum
            count[prefix] = count.get(prefix, 0) + 1
        
        return result
        