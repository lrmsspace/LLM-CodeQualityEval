# You are given an array of positive integers nums.
# An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
# prod(arr) is the product of all elements of arr.
# gcd(arr) is the GCD of all elements of arr.
# lcm(arr) is the LCM of all elements of arr.
# Return the length of the longest product equivalent subarray of nums.
# Example 1:
# Input: nums = [1,2,1,2,1,1,1]
# Output: 5
# Explanation: 
# The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
# Example 2:
# Input: nums = [2,3,4,5,6]
# Output: 3
# Explanation: 
# The longest product equivalent subarray is [3, 4, 5].
# Example 3:
# Input: nums = [1,2,3,1,4,5,1]
# Output: 5
# Constraints:
# 2 <= nums.length <= 100
# 1 <= nums[i] <= 10

class Solution(object):
    def maxLength(self, nums):
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

        def prod(arr):
            result = 1
            for num in arr:
                result *= num
            return result

        n = len(nums)
        dp = [1] * n
        max_length = 1

        for i in range(n):
            for j in range(i):
                if prod(nums[j:i+1]) == lcm(nums[j:i+1]) * gcd(nums[j:i+1]):
                    dp[i] = max(dp[i], dp[j] + 1)

            max_length = max(max_length, dp[i])

        return max_length        