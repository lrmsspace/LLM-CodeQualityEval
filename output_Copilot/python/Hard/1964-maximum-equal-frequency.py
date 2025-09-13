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
        count = collections.Counter(nums) 
        freq = collections.Counter(count.values())
        max_freq = max(freq.keys())
        min_freq = min(freq.keys())
        if len(freq) == 1:
            return len(nums) if max_freq == 1 else len(nums) - max_freq
        elif len(freq) == 2:
            if (max_freq == 1 and freq[max_freq] == 1) or (min_freq == 1 and freq[min_freq] == 1):
                return len(nums) - 1
            elif abs(max_freq - min_freq) == 1 and freq[max_freq] == 1:
                return len(nums) - max_freq + min_freq * freq[min_freq]
            elif abs(max_freq - min_freq) == 1 and freq[min_freq] == 1:
                return len(nums) - min_freq + max_freq * freq[max_freq]
            else:
                return len(nums) - max_freq - min_freq + 1
        else:
            return len(nums) - max_freq - min_freq + 1       