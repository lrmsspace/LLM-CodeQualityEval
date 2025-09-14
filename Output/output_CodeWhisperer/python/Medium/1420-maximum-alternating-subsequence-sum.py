#https://leetcode.com/problems/maximum-alternating-subsequence-sum/
#The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.
#	For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
#Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).
#A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.
# 
#Example 1:
#Input: nums = [4,2,5,3]
#Output: 7
#Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
#Example 2:
#Input: nums = [5,6,7,8]
#Output: 8
#Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.
#Example 3:
#Input: nums = [6,2,1,2,4,5]
#Output: 10
#Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 105
class Solution(object):
    def maxAlternatingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Initialize even and odd sums
        # even_sum: maximum sum when last picked number is at even index
        # odd_sum: maximum sum when last picked number is at odd index
        even_sum = 0
        odd_sum = 0
        
        for num in nums:
            # For each number, we have two choices:
            # 1. Add it to previous odd sum (making it even position)
            # 2. Subtract it from previous even sum (making it odd position)
            
            # Store previous values
            temp_even = even_sum
            temp_odd = odd_sum
            
            # Update even_sum: either keep previous even_sum or 
            # take previous odd_sum and add current number
            even_sum = max(even_sum, temp_odd + num)
            
            # Update odd_sum: either keep previous odd_sum or
            # take previous even_sum and subtract current number
            odd_sum = max(odd_sum, temp_even - num)
        
        # Return maximum of even and odd sums
        return max(even_sum, odd_sum)
    