#https://leetcode.com/problems/number-of-squareful-arrays/
#An array is squareful if the sum of every pair of adjacent elements is a perfect square.
#Given an integer array nums, return the number of permutations of nums that are squareful.
#Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
# 
#Example 1:
#Input: nums = [1,17,8]
#Output: 2
#Explanation: [1,8,17] and [17,8,1] are the valid permutations.
#Example 2:
#Input: nums = [2,2,2]
#Output: 1
# 
#Constraints:
#	1 <= nums.length <= 12
#	0 <= nums[i] <= 109
class Solution(object):
    def numSquarefulPerms(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import Counter

        def is_square(n):
            return int(n**0.5)**2 == n

        def backtrack(path, counter):
            if len(path) == len(nums):
                return 1
            count = 0
            for num in counter:
                if counter[num] > 0:
                    if len(path) == 0 or is_square(path[-1] + num):
                        counter[num] -= 1
                        count += backtrack(path + [num], counter)
                        counter[num] += 1
            return count

        nums.sort()
        counter = Counter(nums)
        return backtrack([], counter)        