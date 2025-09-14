#https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
#A split of an integer array is good if:
#	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
#	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
#Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
# 
#Example 1:
#Input: nums = [1,1,1]
#Output: 1
#Explanation: The only good way to split nums is [1] [1] [1].
#Example 2:
#Input: nums = [1,2,2,2,5,0]
#Output: 3
#Explanation: There are three good ways of splitting nums:
#[1] [2] [2,2,5,0]
#[1] [2,2] [2,5,0]
#[1,2] [2,2] [5,0]
#Example 3:
#Input: nums = [3,2,1]
#Output: 0
#Explanation: There is no good way to split nums.
# 
#Constraints:
#	3 <= nums.length <= 105
#	0 <= nums[i] <= 104
class Solution(object):
    def waysToSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(nums)
        prefix_sum = [0] * (n + 1)
        
        # Calculate prefix sums
        for i in range(n):
            prefix_sum[i+1] = prefix_sum[i] + nums[i]

        count = 0
        
        # Iterate over possible start of "mid" subarray
        for i in range(1, n - 1):
            # Binary search for the smallest j such that sum(left) <= sum(mid)
            left = i + 1
            right = n - 1
            while left < right:
                mid = (left + right) // 2
                if prefix_sum[mid] - prefix_sum[i] < prefix_sum[i]:
                    left = mid + 1
                else:
                    right = mid
            j = left
            
            # Binary search for the largest k such that sum(mid) <= sum(right)
            left = i + 1
            right = n - 1
            while left < right:
                mid = (left + right + 1) // 2
                if prefix_sum[n] - prefix_sum[mid] >= prefix_sum[mid] - prefix_sum[i]:
                    left = mid
                else:
                    right = mid - 1
            k = left
            
            if j <= k:
                count = (count + (k - j + 1)) % MOD
        
        return count

