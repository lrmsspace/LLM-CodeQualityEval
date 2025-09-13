#https://leetcode.com/problems/sort-array-by-parity/
#Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
#Return any array that satisfies this condition.
# 
#Example 1:
#Input: nums = [3,1,2,4]
#Output: [2,4,3,1]
#Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
#Example 2:
#Input: nums = [0]
#Output: [0]
# 
#Constraints:
#	1 <= nums.length <= 5000
#	0 <= nums[i] <= 5000
class Solution(object):
    def sortArrayByParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Two pointers to track even and odd indices
        even, odd = 0, len(nums) - 1
        # Swap elements until even pointer reaches odd pointer
        while even < odd:
            # Swap if current element is even
            if nums[even] % 2 == 0:
                nums[even], nums[odd] = nums[odd], nums[even]
                odd -= 1
            else:
                even += 1
        return nums
        