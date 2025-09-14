#https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
#Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 
#If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 
#Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.
# 
#Example 1:
#Input: nums = [4,3,10,9,8]
#Output: [10,9] 
#Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included. However, the subsequence [10,9] has the maximum total sum of its elements. 
#Example 2:
#Input: nums = [4,4,7,6,7]
#Output: [7,7,6] 
#Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to be returned in non-increasing order.  
# 
#Constraints:
#	1 <= nums.length <= 500
#	1 <= nums[i] <= 100
class Solution(object):
    def minSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Sort the array in descending order
        nums.sort(reverse=True)
        
        # Initialize the sum of the subsequence and the sum of the non-included elements
        subsequence_sum = 0
        non_included_sum = 0
        
        # Initialize an empty list to store the subsequence
        subsequence = []
        
        # Iterate over the sorted array
        for num in nums:
            # Add the current number to the subsequence
            subsequence.append(num)
            
            # Update the sum of the subsequence and the sum of the non-included elements
            subsequence_sum += num
            non_included_sum += non_included_sum + num
            
            # If the sum of the subsequence is strictly greater than the sum of the non-included elements
            if subsequence_sum > non_included_sum:
                # Return the subsequence
                return subsequence
        
        # If no subsequence is found, return an empty list
        return []
        