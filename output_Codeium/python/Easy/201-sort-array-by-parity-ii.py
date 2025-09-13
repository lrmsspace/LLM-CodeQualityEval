#https://leetcode.com/problems/sort-array-by-parity-ii/
#Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
#Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
#Return any answer array that satisfies this condition.
# 
#Example 1:
#Input: nums = [4,2,5,7]
#Output: [4,5,2,7]
#Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
#Example 2:
#Input: nums = [2,3]
#Output: [2,3]
# 
#Constraints:
#	2 <= nums.length <= 2 * 104
#	nums.length is even.
#	Half of the integers in nums are even.
#	0 <= nums[i] <= 1000
# 
#Follow Up: Could you solve it in-place?
class Solution(object):
    def sortArrayByParityII(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        even = 0
        for i in range(len(nums)):
            if i % 2 == 0 and nums[i] % 2 != 0:
                while nums[even] % 2 != 0:
                    even += 2
                nums[i], nums[even] = nums[even], nums[i]
            elif i % 2 == 1 and nums[i] % 2 != 1:
                while nums[even+1] % 2 != 1:
                    even += 2
                nums[i], nums[even+1] = nums[even+1], nums[i]
        return nums
