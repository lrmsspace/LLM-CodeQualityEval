# You are given an integer array nums.
# The factor score of an array is defined as the product of the LCM and GCD of all elements of that array.
# Return the maximum factor score of nums after removing at most one element from it.
# Note that both the LCM and GCD of a single number are the number itself, and the factor score of an empty array is 0.
# Example 1:
# Input: nums = [2,4,8,16]
# Output: 64
# Explanation:
# On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of 4 * 16 = 64.
# Example 2:
# Input: nums = [1,2,3,4,5]
# Output: 60
# Explanation:
# The maximum factor score of 60 can be obtained without removing any elements.
# Example 3:
# Input: nums = [3]
# Output: 9
# Constraints:
# 1 <= nums.length <= 100
# 1 <= nums[i] <= 30

class Solution(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        def lcm(a, b):
            return a * b // gcd(a, b)

        def get_factor_score(arr):
            if not arr:
                return 0
            if len(arr) == 1:
                return arr[0]
            lcm_val = arr[0]
            gcd_val = arr[0]
            for i in range(1, len(arr)):
                lcm_val = lcm(lcm_val, arr[i])
                gcd_val = gcd(gcd_val, arr[i])
            return lcm_val * gcd_val

        max_score = 0
        for i in range(len(nums)):
            score = get_factor_score(nums[:i] + nums[i+1:])
            max_score = max(max_score, score)
        return max_score        