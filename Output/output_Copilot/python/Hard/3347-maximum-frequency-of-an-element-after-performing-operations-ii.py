# You are given an integer array nums and two integers k and numOperations.
# You must perform an operation numOperations times on nums, where in each operation you:
# Select an index i that was not selected in any previous operations.
# Add an integer in the range [-k, k] to nums[i].
# Return the maximum possible frequency of any element in nums after performing the operations.
# Example 1:
# Input: nums = [1,4,5], k = 1, numOperations = 2
# Output: 2
# Explanation:
# We can achieve a maximum frequency of two by:
# Adding 0 to nums[1], after which nums becomes [1, 4, 5].
# Adding -1 to nums[2], after which nums becomes [1, 4, 4].
# Example 2:
# Input: nums = [5,11,20,20], k = 5, numOperations = 1
# Output: 2
# Explanation:
# We can achieve a maximum frequency of two by:
# Adding 0 to nums[1].
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109
# 0 <= k <= 109
# 0 <= numOperations <= nums.length

class Solution(object):
    def maxFrequency(self, nums, k, numOperations):
        """
        :type nums: List[int]
        :type k: int
        :type numOperations: int
        :rtype: int
        """
        from collections import Counter
        
        # Count the frequency of each number in nums
        freq = Counter(nums)
        
        # Sort the numbers based on their values
        sorted_nums = sorted(freq.keys())
        
        max_freq = 0
        
        # Iterate through each unique number in sorted order
        for num in sorted_nums:
            current_freq = freq[num]
            operations_left = numOperations
            
            # Try to increase the frequency of the current number
            for other_num in sorted_nums:
                if other_num == num:
                    continue
                
                # Calculate the difference and how many operations are needed
                diff = abs(other_num - num)
                needed_operations = (current_freq + 1) * diff
                
                if needed_operations <= operations_left:
                    operations_left -= needed_operations
                    current_freq += 1
            
            max_freq = max(max_freq, current_freq)
        
        return max_freq
        