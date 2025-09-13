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
        primes = set()
        for num in nums:
            if self.is_prime(num):
                primes.add(num)
        
        if len(primes) < 2:
            return 0
        
        min_prime = min(primes)
        max_prime = max(primes)
        
        max_diff = 0
        for prime in primes:
            diff = max_prime - prime
            if diff > max_diff:
                max_diff = diff
        
        return max_diff
        