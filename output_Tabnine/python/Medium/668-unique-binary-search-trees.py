#https://leetcode.com/problems/unique-binary-search-trees/
#Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
# 
#Example 1:
#Input: n = 3
#Output: 5
#Example 2:
#Input: n = 1
#Output: 1
# 
#Constraints:
#	1 <= n <= 19
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize an array to store the number of unique BSTs for each number of nodes
        dp = [0] * (n + 1)
        
        # Base case: 1 node has 1 unique BST
        dp[0] = 1
        
        # Fill the dp array
        for i in range(1, n + 1):
            for j in range(i):
                # Number of unique BSTs for i nodes is the sum of the number of unique BSTs for j nodes on the left
                # and the number of unique BSTs for (i - j - 1) nodes on the right
                dp[i] += dp[j] * dp[i - j - 1]
        
        return dp[n]
        