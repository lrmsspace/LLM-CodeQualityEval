#https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
#You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
#Return the minimum possible absolute difference.
# 
#Example 1:
#Input: nums = [3,9,7,3]
#Output: 2
#Explanation: One optimal partition is: [3,9] and [7,3].
#The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
#Example 2:
#Input: nums = [-36,36]
#Output: 72
#Explanation: One optimal partition is: [-36] and [36].
#The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
#Example 3:
#Input: nums = [2,-1,0,4,-2,-9]
#Output: 0
#Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
#The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
# 
#Constraints:
#	1 <= n <= 15
#	nums.length == 2 * n
#	-107 <= nums[i] <= 107
class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums) // 2
        total = sum(nums)
        dp = {0}
        for i in range(n):
            dp |= {x + nums[i] for x in dp}
        dp = list(dp)
        dp.sort()
        m = len(dp)
        ans = float('inf')
        for i in range(m):
            j = bisect.bisect_left(dp, (total - dp[i]) // 2)
            if j < m:
                ans = min(ans, abs(total - 2 * (dp[i] + dp[j])))
            if j > 0:
                ans = min(ans, abs(total - 2 * (dp[i] + dp[j - 1])))
        return ans        