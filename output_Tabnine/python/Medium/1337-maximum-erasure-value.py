#https://leetcode.com/problems/maximum-erasure-value/
#You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
#Return the maximum score you can get by erasing exactly one subarray.
#An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
# 
#Example 1:
#Input: nums = [4,2,4,5,6]
#Output: 17
#Explanation: The optimal subarray here is [2,4,5,6].
#Example 2:
#Input: nums = [5,2,1,2,5,2,1,2,5]
#Output: 8
#Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 104
class Solution(object):
    def maximumUniqueSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize variables
        max_score = 0
        unique_nums = set()
        left = 0
        right = 0
        
        while right < len(nums):
            # Add current number to unique_nums set
            unique_nums.add(nums[right])
            
            # Calculate score by subtracting left number and adding right number
            score = sum(nums[left:right+1])
            
            # Update max_score if new score is greater
            max_score = max(max_score, score)
            
            # Move left pointer to the right until we find a duplicate number
            while nums[right] in unique_nums:
                unique_nums.remove(nums[left])
                left += 1
            
            # Move right pointer to the right
            right += 1
        
        return max_score    
        