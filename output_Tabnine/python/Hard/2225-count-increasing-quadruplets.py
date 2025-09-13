#https://leetcode.com/problems/count-increasing-quadruplets/
#Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.
#A quadruplet (i, j, k, l) is increasing if:
#	0 <= i < j < k < l < n, and
#	nums[i] < nums[k] < nums[j] < nums[l].
# 
#Example 1:
#Input: nums = [1,3,2,4,5]
#Output: 2
#Explanation: 
#- When i = 0, j = 1, k = 2, and l = 3, nums[i] < nums[k] < nums[j] < nums[l].
#- When i = 0, j = 1, k = 2, and l = 4, nums[i] < nums[k] < nums[j] < nums[l]. 
#There are no other quadruplets, so we return 2.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: 0
#Explanation: There exists only one quadruplet with i = 0, j = 1, k = 2, l = 3, but since nums[j] < nums[k], we return 0.
# 
#Constraints:
#	4 <= nums.length <= 4000
#	1 <= nums[i] <= nums.length
#	All the integers of nums are unique. nums is a permutation.
class Solution(object):
    def countQuadruplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize the count of quadruplets to 0
        count = 0
        
        # Sort the array
        nums.sort()
        
        # Iterate over the array from index 3 (the fourth element) to the end
        for i in range(3, len(nums)):
            # Initialize two pointers, left and right, to the left and right ends of the array, respectively
            left, right = 0, i - 1
            
            # Iterate over the array from index 0 (the first element) to the current index - 1
            while left < right:
                # If the sum of the current element, the left element, and the right element is greater than or equal to the next element
                if nums[i] >= nums[left] + nums[right]:
                    # Increment the count of quadruplets
                    count += right - left
                    # Move the left pointer to the right
                    left += 1
                else:
                    # Move the right pointer to the left
                    right -= 1
        
        # Return the count of quadruplets
        return count
        