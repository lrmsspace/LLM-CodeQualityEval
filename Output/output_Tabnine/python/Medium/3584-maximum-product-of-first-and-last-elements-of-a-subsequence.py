# You are given an integer array nums and an integer m.
# Return the maximum product of the first and last elements of any subsequence of nums of size m.
# Example 1:
# Input: nums = [-1,-9,2,3,-2,-3,1], m = 1
# Output: 81
# Explanation:
# The subsequence [-9] has the largest product of the first and last elements: -9 * -9 = 81. Therefore, the answer is 81.
# Example 2:
# Input: nums = [1,3,-5,5,6,-4], m = 3
# Output: 20
# Explanation:
# The subsequence [-5, 6, -4] has the largest product of the first and last elements.
# Example 3:
# Input: nums = [2,-1,2,-6,5,2,-5,7], m = 2
# Output: 35
# Explanation:
# The subsequence [5, 7] has the largest product of the first and last elements.
# Constraints:
# 1 <= nums.length <= 105
# -105 <= nums[i] <= 105
# 1 <= m <= nums.length

class Solution(object):
    def maximumProduct(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        # Sort the array in descending order
        nums.sort(reverse=True)
        
        # Initialize variables to store the maximum product and the current product
        max_product = float('-inf')
        current_product = 1
        
        # Iterate through the array
        for i in range(m - 1, len(nums)):
            # Update the current product
            current_product *= nums[i]
            
            # Update the maximum product if necessary
            max_product = max(max_product, current_product)
        
        return max_product
        