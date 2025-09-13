#https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
#You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
#Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
# 
#Example 1:
#Input: nums = [18,43,36,13,7]
#Output: 54
#Explanation: The pairs (i, j) that satisfy the conditions are:
#- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
#- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
#So the maximum sum that we can obtain is 54.
#Example 2:
#Input: nums = [10,12,19,14]
#Output: -1
#Explanation: There are no two numbers that satisfy the conditions, so we return -1.
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 109
class Solution(object):
    def maximumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Sort the array in ascending order
        nums.sort()
        
        # Initialize the maximum sum as -1
        max_sum = -1
        
        # Iterate through the array from the second last element to the first element
        for i in range(len(nums) - 1, 0, -1):
            # Check if the sum of digits of the current number and the next number is equal
            if sum(int(digit) for digit in str(nums[i])) == sum(int(digit) for digit in str(nums[i - 1])):
                # Update the maximum sum if a pair satisfies the condition
                max_sum = max(max_sum, nums[i] + nums[i - 1])
        
        # Return the maximum sum
        return max_sum
        