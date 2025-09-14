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
        n = len(nums)
        k_index = nums.index(k)
        left = right = 0
        count = 0

        # Count subarrays to the left of k
        for i in range(k_index - 1, -1, -1):
            if nums[i] < k:
                left += 1
            else:
                break

        # Count subarrays to the right of k
        for i in range(k_index + 1, n):
            if nums[i] > k:
                right += 1
            else:
                break

        # Count subarrays that include k and have a median equal to k
        count += (left + 1) * (right + 1)

        # Count subarrays that do not include k and have a median equal to k
        for i in range(k_index - left, k_index + right + 1):
            if nums[i] < k:
                count += left + 1
            elif nums[i] > k:
                count += right + 1

        return count        