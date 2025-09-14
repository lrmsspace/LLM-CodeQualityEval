#https://leetcode.com/problems/132-pattern/
#Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
#Return true if there is a 132 pattern in nums, otherwise, return false.
# 
#Example 1:
#Input: nums = [1,2,3,4]
#Output: false
#Explanation: There is no 132 pattern in the sequence.
#Example 2:
#Input: nums = [3,1,4,2]
#Output: true
#Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
#Example 3:
#Input: nums = [-1,3,2,0]
#Output: true
#Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 2 * 105
#	-109 <= nums[i] <= 109
class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # Initialize a stack to keep track of the increasing subsequence
        stack = []
        
        # Iterate through the array from right to left
        for i in range(len(nums) - 1, -1, -1):
            # If the current number is greater than the top of the stack,
            # it means we found a potential 132 pattern
            if stack and stack[-1] < nums[i]:
                # Pop elements from the stack until we find a number that is less than the current number
                while stack and stack[-1] < nums[i]:
                    third = stack.pop()
                # Push the current number into the stack
                stack.append(nums[i])
                # If the current number is less than the third number, we found a 132 pattern
                if stack and stack[-1] < third:
                    return True
        
        # No 132 pattern found
        return False
        