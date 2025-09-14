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
        mod = 10**9 + 7
        n = len(nums)
        result = 0
        freq = {}
        
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        for i in range(n - 4):
            for j in range(i + 1, n - 3):
                for k in range(j + 1, n - 2):
                    for l in range(k + 1, n - 1):
                        for m in range(l + 1, n):
                            subseq_freq = {nums[i]: 1, nums[j]: 1, nums[k]: 1, nums[l]: 1, nums[m]: 1}
                            
                            is_unique_mode = True
                            middle_value = nums[k]
                            middle_freq = subseq_freq[middle_value]
                            for key, value in subseq_freq.items():
                                if key != middle_value and value >= middle_freq:
                                    is_unique_mode = False
                                    break
                            
                            if is_unique_mode:
                                result = (result + 1) % mod
        
        return result
