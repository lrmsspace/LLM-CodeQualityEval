# You are given two integer arrays arr and brr of length n, and an integer k. You can perform the following operations on arr any number of times:
# Split arr into any number of contiguous subarrays and rearrange these subarrays in any order. This operation has a fixed cost of k.
# Choose any element in arr and add or subtract a positive integer x to it. The cost of this operation is x.
# Return the minimum total cost to make arr equal to brr.
# Example 1:
# Input: arr = [-7,9,5], brr = [7,-2,-5], k = 2
# Output: 13
# Explanation:
# Split arr into two contiguous subarrays: [-7] and [9, 5] and rearrange them as [9, 5, -7], with a cost of 2.
# Subtract 2 from element arr[0]. The array becomes [7, 5, -7]. The cost of this operation is 2.
# Subtract 7 from element arr[1]. The array becomes [7, -2, -7]. The cost of this operation is 7.
# Add 2 to element arr[2]. The array becomes [7, -2, -5]. The cost of this operation is 2.
# The total cost to make the arrays equal is 2 + 2 + 7 + 2 = 13.
# Example 2:
# Input: arr = [2,1], brr = [2,1], k = 0
# Output: 0
# Explanation:
# Since the arrays are already equal, no operations are needed, and the total cost is 0.
# Constraints:
# 1 <= arr.length == brr.length <= 105
# 0 <= k <= 2 * 1010
# -105 <= arr[i] <= 105
# -105 <= brr[i] <= 105

class Solution(object):
    def minCost(self, arr, brr, k):
        """
        :type arr: List[int]
        :type brr: List[int]
        :type k: int
        :rtype: int
        """
        # Calculate the difference between the two arrays
        diff = [abs(a - b) for a, b in zip(arr, brr)]
        
        # Sort the difference array in ascending order
        diff.sort()
        
        # Initialize the total cost
        total_cost = 0
        
        # Iterate through the difference array
        for i in range(len(diff)):
            # If the total cost is less than or equal to k, add the current difference to the total cost
            if total_cost + diff[i] <= k:
                total_cost += diff[i]
            # Otherwise, subtract the current difference from k and add it to the total cost
            else:
                total_cost += k - (total_cost + diff[i]) - 1
        
        return total_cost
        