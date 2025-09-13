# You are given an array of integers nums of size 3.
# Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.
# Note that the binary representation of any number does not contain leading zeros.
# Example 1:
# Input: nums = [1,2,3]
# Output: 30
# Explanation:
# Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
# Example 2:
# Input: nums = [2,8,16]
# Output: 1296
# Explanation:
# Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.
# Constraints:
# nums.length == 3
# 1 <= nums[i] <= 127

class Solution(object):
    def maxGoodNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Convert each number to binary, remove leading zeros, and sort the binary representation in descending order
        sorted_binaries = sorted(bin(num)[2:].zfill(7) for num in nums, reverse=True)
        
        # Find the maximum number that can be formed by concatenating the sorted binary representations
        max_num = 0
        for binary in sorted_binaries:
            max_num = (max_num << 7) + int(binary, 2)
        
        return max_num  
        