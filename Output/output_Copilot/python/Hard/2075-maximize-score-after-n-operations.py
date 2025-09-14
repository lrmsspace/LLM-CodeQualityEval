#https://leetcode.com/problems/maximize-score-after-n-operations/
#You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
#In the ith operation (1-indexed), you will:
#	Choose two elements, x and y.
#	Receive a score of i * gcd(x, y).
#	Remove x and y from nums.
#Return the maximum score you can receive after performing n operations.
#The function gcd(x, y) is the greatest common divisor of x and y.
# 
#Example 1:
#Input: nums = [1,2]
#Output: 1
#Explanation: The optimal choice of operations is:
#(1 * gcd(1, 2)) = 1
#Example 2:
#Input: nums = [3,4,6,8]
#Output: 11
#Explanation: The optimal choice of operations is:
#(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
#Example 3:
#Input: nums = [1,2,3,4,5,6]
#Output: 14
#Explanation: The optimal choice of operations is:
#(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
# 
#Constraints:
#	1 <= n <= 7
#	nums.length == 2 * n
#	1 <= nums[i] <= 106
class Solution(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from math import gcd
        from itertools import combinations

        n = len(nums) // 2
        dp = [0] * (1 << (2 * n))

        for mask in range(1 << (2 * n)):
            cnt = bin(mask).count('1')
            if cnt % 2 == 1:
                continue
            for i, j in combinations(range(2 * n), 2):
                if mask & (1 << i) == 0 and mask & (1 << j) == 0:
                    new_mask = mask | (1 << i) | (1 << j)
                    dp[new_mask] = max(dp[new_mask], dp[mask] + (cnt // 2 + 1) * gcd(nums[i], nums[j]))

        return dp[(1 << (2 * n)) - 1]        