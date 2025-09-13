#https://leetcode.com/problems/special-permutations/
#You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:
#	For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
#Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.
# 
#Example 1:
#Input: nums = [2,3,6]
#Output: 2
#Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
#Example 2:
#Input: nums = [1,4,3]
#Output: 2
#Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
# 
#Constraints:
#	2 <= nums.length <= 14
#	1 <= nums[i] <= 109
class Solution(object):
    def specialPerm(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        mod = 10**9 + 7

        # Precompute the adjacency matrix
        adj = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] % nums[j] == 0 or nums[j] % nums[i] == 0:
                    adj[i][j] = adj[j][i] = 1

        # DP table to store the number of special permutations ending with each number
        dp = [0] * (1 << n)
        dp[1] = 1  
        for mask in range(1 << n):
            for i in range(n):
                if mask & (1 << i):
                    for j in range(n):
                        if not (mask & (1 << j)) and adj[i][j]:
                            dp[mask | (1 << j)] = (dp[mask | (1 << j)] + dp[mask]) % mod
        result = 0
        for mask in range(1 << n):
            if bin(mask).count('1') == n:
                result = (result + dp[mask]) % mod
        return result      