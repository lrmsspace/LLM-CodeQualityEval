# You are given an integer array nums.
# Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
# Example 1:
# Input: nums = [4,2,9,5,3]
# Output: 3
# Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.
# Example 2:
# Input: nums = [4,8,2,8]
# Output: 0
# Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.
# Constraints:
# 1 <= nums.length <= 3 * 105
# 1 <= nums[i] <= 100
# The input is generated such that the number of prime numbers in the nums is at least one.

class Solution(object):
    def maximumPrimeDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        primes = []
        for i in range(len(nums)):
            if self.is_prime(nums[i]):
                primes.append(i)

        max_diff = 0
        for i in range(len(primes)):
            for j in range(i, len(primes)):
                max_diff = max(max_diff, abs(primes[j] - primes[i]))

        return max_diff

    def is_prime(self, n):
        if n <= 1:
            return False
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
        return True