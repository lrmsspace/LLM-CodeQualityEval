#https://leetcode.com/problems/count-number-of-nice-subarrays/
#Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
#Return the number of nice sub-arrays.
# 
#Example 1:
#Input: nums = [1,1,2,1,1], k = 3
#Output: 2
#Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
#Example 2:
#Input: nums = [2,4,6], k = 1
#Output: 0
#Explanation: There are no odd numbers in the array.
#Example 3:
#Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
#Output: 16
# 
#Constraints:
#	1 <= nums.length <= 50000
#	1 <= nums[i] <= 10^5
#	1 <= k <= nums.length
class Solution(object):
    def numberOfSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = 0
        left = 0
        odd_count = 0
        for right in range(len(nums)):
            if nums[right] % 2 == 1:
                odd_count += 1
            while odd_count > k:
                if nums[left] % 2 == 1:
                    odd_count -= 1
                left += 1
            if odd_count == k:
                count += 1
                temp_left = left
                while temp_left < right and nums[temp_left] % 2 == 0:
                    count += 1
                    temp_left += 1
        return count        