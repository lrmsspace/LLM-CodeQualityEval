#https://leetcode.com/problems/maximum-equal-frequency/
#Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.
#If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).
# 
#Example 1:
#Input: nums = [2,2,1,1,5,3,3,5]
#Output: 7
#Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4] = 5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
#Example 2:
#Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
#Output: 13
# 
#Constraints:
#	2 <= nums.length <= 105
#	1 <= nums[i] <= 105
class Solution(object):
    def maxEqualFreq(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        freq = {}
        count = {}
        ans = 0
        
        for i, num in enumerate(nums):
            if num in freq:
                freq[num] -= 1
                if freq[num] == 0:
                    del freq[num]
            freq[num] = freq.get(num, 0) + 1
            count[freq[num]] = count.get(freq[num], 0) + 1
            
            while count[freq[num]] > 1:
                count[freq[num] - 1] -= 1
                if count[freq[num] - 1] == 0:
                    del count[freq[num] - 1]
                freq[nums[ans]] -= 1
                if freq[nums[ans]] == 0:
                    del freq[nums[ans]]
                ans += 1
        
        return i + 1
        