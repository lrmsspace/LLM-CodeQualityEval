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
        d = collections.defaultdict(int)
        for i in nums:
            d[i] += 1
        freq = collections.defaultdict(int)
        for i in d.values():
            freq[i] += 1
        if len(freq) == 1:
            return len(nums)
        if len(freq) == 2:
            if 1 in freq.values():
                return len(nums)
            else:
                return len(nums) - 2
        if len(freq) == 3:
            if 1 in freq.values():
                return len(nums) - 2
            else:
                return len(nums) - 3
        for i in range(len(nums)-1, 0, -1):
            if d[nums[i]] == 1:
                continue
            else:
                d[nums[i]] -= 1
                freq[d[nums[i]]] -= 1
                if freq[d[nums[i]]] == 0:
                    del freq[d[nums[i]]]
                if len(freq) == 1:
                    return i
                if len(freq) == 2:
                    if 1 in freq.values():
                        return i
                    else:
                        return i -2
        return 1 