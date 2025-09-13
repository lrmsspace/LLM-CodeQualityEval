#https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/
#Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.
#A subarray is a contiguous non-empty sequence of elements within an array.
#The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.
# 
#Example 1:
#Input: nums = [3,6,2,7,1], k = 6
#Output: 4
#Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
#- [3,6,2,7,1]
#- [3,6,2,7,1]
#- [3,6,2,7,1]
#- [3,6,2,7,1]
#Example 2:
#Input: nums = [3], k = 2
#Output: 0
#Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.
# 
#Constraints:
#	1 <= nums.length <= 1000
#	1 <= nums[i], k <= 1000
class Solution(object):
    def subarrayLCM(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        res = 0
        
        # For every possible length of subarray
        for i in range(1, n+1):
            # For every possible start index of subarray
            for j in range(n-i+1):
                # Calculate the least common multiple of elements in the subarray
                lcm = nums[j]
                for num in nums[j+1:j+i]:
                    lcm = lcm * num // math.gcd(lcm, num)
                
                # If the least common multiple is k, increment the result
                if lcm == k:
                    res += 1
        
        return res
        