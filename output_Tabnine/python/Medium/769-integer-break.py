#https://leetcode.com/problems/integer-break/
#Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
#Return the maximum product you can get.
# 
#Example 1:
#Input: n = 2
#Output: 1
#Explanation: 2 = 1 + 1, 1 × 1 = 1.
#Example 2:
#Input: n = 10
#Output: 36
#Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
# 
#Constraints:
#	2 <= n <= 58
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize a list to store the maximum product for each possible value of k
        dp = [0] * (n + 1)
        
        # Iterate from 2 to n
        for k in range(2, n + 1):
            # Initialize the maximum product for the current value of k as the minimum value
            max_product = float('-inf')
            
            # Iterate from 1 to k-1
            for i in range(1, k):
                # Calculate the current product and update the maximum product
                current_product = i * (k - i)
                max_product = max(max_product, current_product)
            
            # Store the maximum product for the current value of k
            dp[k] = max_product
        
        # Return the maximum product for the given value of n
        return dp[n]
        