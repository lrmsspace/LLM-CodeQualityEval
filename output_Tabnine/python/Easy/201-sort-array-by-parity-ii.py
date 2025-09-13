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
        # Two pointers: one for odd indices and one for even indices
        i, j = 0, 1
        
        # Traverse the array
        while i < len(nums) and j < len(nums):
            # If the current element at odd index is odd or at even index is even, move on
            if nums[i] % 2 == 1 or nums[j] % 2 == 0:
                i += 2
                j += 2
            else:
                # Swap elements at odd index and even index
                nums[i], nums[j] = nums[j], nums[i]
                i += 2
                j += 2
        
        return nums
        