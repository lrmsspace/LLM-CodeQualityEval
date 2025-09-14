# You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.
# Your task is to assign a height to each tower so that:
# The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
# No two towers have the same height.
# Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.
# Example 1:
# Input: maximumHeight = [2,3,4,3]
# Output: 10
# Explanation:
# We can assign heights in the following way: [1, 2, 4, 3].
# Example 2:
# Input: maximumHeight = [15,10]
# Output: 25
# Explanation:
# We can assign heights in the following way: [15, 10].
# Example 3:
# Input: maximumHeight = [2,2,1]
# Output: -1
# Explanation:
# It's impossible to assign positive heights to each index so that no two towers have the same height.
# Constraints:
# 1 <= maximumHeight.length <= 105
# 1 <= maximumHeight[i] <= 109

class Solution(object):
    def maximumTotalSum(self, maximumHeight):
        """
        :type maximumHeight: List[int]
        :rtype: int
        """
        # Sort the maximumHeight array in descending order
        maximumHeight.sort(reverse=True)
        
        # Initialize the maximum sum to 0
        max_sum = 0
        
        # Iterate through the maximumHeight array
        for i in range(len(maximumHeight)):
            # If the current height is greater than or equal to the index + 1,
            # add it to the maximum sum
            if maximumHeight[i] >= i + 1:
                max_sum += maximumHeight[i]
        
        # Return the maximum possible total sum
        return max_sum
        