#https://leetcode.com/problems/find-k-th-smallest-pair-distance/
#The distance of a pair of integers a and b is defined as the absolute difference between a and b.
#Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
# 
#Example 1:
#Input: nums = [1,3,1], k = 1
#Output: 0
#Explanation: Here are all the pairs:
#(1,3) -> 2
#(1,1) -> 0
#(3,1) -> 2
#Then the 1st smallest distance pair is (1,1), and its distance is 0.
#Example 2:
#Input: nums = [1,1,1], k = 2
#Output: 0
#Example 3:
#Input: nums = [1,6,1], k = 3
#Output: 5
# 
#Constraints:
#	n == nums.length
#	2 <= n <= 104
#	0 <= nums[i] <= 106
#	1 <= k <= n * (n - 1) / 2
class Solution(object):
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def search(low, high):
            count = 0
            j = len(nums) - 1
            for i in range(len(nums) - 1):
                while j > i and nums[j] - nums[i] > high:
                    j -= 1
                count += j - i
                if nums[j] - nums[i] >= low:
                    k -= 1
                if k == 0:
                    return nums[j] - nums[i]
            return -1
        nums.sort()
        low, high = 0, nums[-1] - nums[0]
        while low < high:
            mid = (low + high) // 2
            kth_smallest = search(low, mid)
            if kth_smallest == -1:
                high = mid
            else:
                low = kth_smallest
        return low
