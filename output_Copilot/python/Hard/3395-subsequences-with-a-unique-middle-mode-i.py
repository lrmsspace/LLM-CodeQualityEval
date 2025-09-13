# Given an integer array nums, find the number of subsequences of size 5 of nums with a unique middle mode.
# Since the answer may be very large, return it modulo 109 + 7.
# A mode of a sequence of numbers is defined as the element that appears the maximum number of times in the sequence.
# A sequence of numbers contains a unique mode if it has only one mode.
# A sequence of numbers seq of size 5 contains a unique middle mode if the middle element (seq[2]) is a unique mode.
# Example 1:
# Input: nums = [1,1,1,1,1,1]
# Output: 6
# Explanation:
# [1, 1, 1, 1, 1] is the only subsequence of size 5 that can be formed, and it has a unique middle mode of 1. This subsequence can be formed in 6 different ways, so the output is 6. 
# Example 2:
# Input: nums = [1,2,2,3,3,4]
# Output: 4
# Explanation:
# [1, 2, 2, 3, 4] and [1, 2, 3, 3, 4] each have a unique middle mode because the number at index 2 has the greatest frequency in the subsequence. [1, 2, 2, 3, 3] does not have a unique middle mode because 2 and 3 appear twice.
# Example 3:
# Input: nums = [0,1,2,3,4,5,6,7,8]
# Output: 0
# Explanation:
# There is no subsequence of length 5 with a unique middle mode.
# Constraints:
# 5 <= nums.length <= 1000
# -109 <= nums[i] <= 109

class Solution(object):
    def subsequencesWithMiddleMode(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import Counter
        from math import comb

        MOD = 10**9 + 7
        
        # Count frequency of each number
        freq = Counter(nums)
        
        # If there are less than 3 unique numbers, return 0
        if len(freq) < 3:
            return 0
        
        total_count = 0
        
        # Iterate through each unique number as the middle mode
        for mid in freq:
            mid_count = freq[mid]
            if mid_count < 2:
                continue
            
            # Count how many numbers are less than and greater than the middle mode
            less_count = sum(f for num, f in freq.items() if num < mid)
            greater_count = sum(f for num, f in freq.items() if num > mid)
            
            # Calculate the number of valid subsequences with this middle mode
            if less_count >= 2 and greater_count >= 2:
                total_count += comb(less_count, 2) * comb(greater_count, 2) * comb(mid_count, 1)
                total_count %= MOD
        
        return total_count
        