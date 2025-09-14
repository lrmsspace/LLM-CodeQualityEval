#https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
#Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
# 
#Example 1:
#Input: nums = [4,3,2,3,5,2,1], k = 4
#Output: true
#Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
#Example 2:
#Input: nums = [1,2,3,4], k = 3
#Output: false
# 
#Constraints:
#	1 <= k <= nums.length <= 16
#	1 <= nums[i] <= 104
#	The frequency of each element is in the range [1, 4].
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        total = sum(nums)
        if total % k != 0:
            return False
        target = total // k
        nums.sort(reverse=True)
        buckets = [0] * k

        def backtrack(index):
            if index == len(nums):
                return all(bucket == target for bucket in buckets)
            for i in range(k):
                if buckets[i] + nums[index] <= target:
                    buckets[i] += nums[index]
                    if backtrack(index + 1):
                        return True
                    buckets[i] -= nums[index]
                if buckets[i] == 0:   # If the current bucket is empty, no need to try other empty buckets
                    break
            return False
        return backtrack(0)     