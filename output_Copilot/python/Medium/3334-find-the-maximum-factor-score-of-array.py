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

        def gcd(x, y):
            while y:
                x, y = y, x % y
            return x

        def lcm(x, y):
            return x * y // gcd(x, y)

        max_score = 0
        for i in range(len(nums)):
            temp = nums[:i] + nums[i + 1:]
            if not temp:
                continue
            current_gcd = temp[0]
            current_lcm = temp[0]
            for num in temp[1:]:
                current_gcd = gcd(current_gcd, num)
                current_lcm = lcm(current_lcm, num)
            max_score = max(max_score, current_gcd * current_lcm)
        return max_score
