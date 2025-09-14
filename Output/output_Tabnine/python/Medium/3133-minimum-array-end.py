# You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.
# Return the minimum possible value of nums[n - 1].
# Example 1:
# Input: n = 3, x = 4
# Output: 6
# Explanation:
# nums can be [4,5,6] and its last element is 6.
# Example 2:
# Input: n = 2, x = 7
# Output: 15
# Explanation:
# nums can be [7,15] and its last element is 15.
# Constraints:
# 1 <= n, x <= 108

class Solution(object):
    def minEnd(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: int
        """
        # Initialize the result as the smallest possible value
        result = x
        
        # Iterate from n - 2 to 0
        for i in range(n - 2, -1, -1):
            # Find the largest number less than or equal to result that is divisible by 2
            j = result // 2 * 2
            
            # If j is less than or equal to x, update result
            if j <= x:
                result = j
        
        # Return the minimum possible value of nums[n - 1]
        return result
        