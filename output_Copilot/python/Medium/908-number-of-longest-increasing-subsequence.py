#https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#Given an integer array nums, return the number of longest increasing subsequences.
#Notice that the sequence has to be strictly increasing.
# 
#Example 1:
#Input: nums = [1,3,5,4,7]
#Output: 2
#Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
#Example 2:
#Input: nums = [2,2,2,2,2]
#Output: 5
#Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
# 
#Constraints:
#	1 <= nums.length <= 2000
#	-106 <= nums[i] <= 106
#	The answer is guaranteed to fit inside a 32-bit integer.
class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        n = len(nums)
        dp = [1] * n       
        count = [1] * n
        max_length = 1
        max_count = 1
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        count[i] = count[j]
                    elif dp[j] + 1 == dp[i]:
                        count[i] += count[j]
            if dp[i] > max_length:
                max_length = dp[i]
                max_count = count[i]
            elif dp[i] == max_length:
                max_count += count[i]
        return max_count     