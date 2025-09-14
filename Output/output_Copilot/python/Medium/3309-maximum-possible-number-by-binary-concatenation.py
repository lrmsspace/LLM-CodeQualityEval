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
        def binary_length(n):
            return len(bin(n)) - 2       
        def binary_concat(a, b):
            return (a << binary_length(b)) | b
        from itertools import permutations
        max_number = 0
        for perm in permutations(nums):
            current = binary_concat(perm[0], binary_concat(perm[1], perm[2]))
            max_number = max(max_number, current)
        return max_number