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
        def search(groups):
            if not nums:
                return True
            v = nums.pop()
            for i, group in enumerate(groups):
                if group + v <= target:
                    groups[i] += v
                    if search(groups):
                        return True
                    groups[i] -= v
                if not group:
                    break
            nums.append(v)
            return False
        
        nums.sort()
        if sum(nums) % k:
            return False
        target = sum(nums) // k
        if nums[-1] > target:
            return False
        while nums and nums[-1] == target:
            nums.pop()
            k -= 1
        return search([0] * k)
