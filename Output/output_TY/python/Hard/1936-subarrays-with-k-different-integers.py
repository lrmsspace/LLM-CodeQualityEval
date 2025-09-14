#https://leetcode.com/problems/subarrays-with-k-different-integers/
#Given an integer array nums and an integer k, return the number of good subarrays of nums.
#A good array is an array where the number of different integers in that array is exactly k.
#	For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
#A subarray is a contiguous part of an array.
# 
#Example 1:
#Input: nums = [1,2,1,2,3], k = 2
#Output: 7
#Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
#Example 2:
#Input: nums = [1,2,1,3,4], k = 3
#Output: 3
#Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
# 
#Constraints:
#	1 <= nums.length <= 2 * 104
#	1 <= nums[i], k <= nums.length
class Solution(object):
    def subarraysWithKDistinct(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans = 0
        left = 0
        count = collections.defaultdict(int)
        for right in range(len(nums)):
            count[nums[right]] += 1
            while len(count) > k:
                count[nums[left]] -= 1
                if count[nums[left]] == 0:
                    del count[nums[left]]
                left += 1
            if len(count) == k:
                ans += 1
                tmp = left
                while count[nums[tmp]] > 1:
                    count[nums[tmp]] -= 1
                    tmp+= 1
        ans += tmp - left + 1
        return ans