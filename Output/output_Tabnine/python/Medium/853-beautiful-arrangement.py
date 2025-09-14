#https://leetcode.com/problems/beautiful-arrangement/
#Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
#	perm[i] is divisible by i.
#	i is divisible by perm[i].
#Given an integer n, return the number of the beautiful arrangements that you can construct.
# 
#Example 1:
#Input: n = 2
#Output: 2
#Explanation: 
#The first beautiful arrangement is [1,2]:
#    - perm[1] = 1 is divisible by i = 1
#    - perm[2] = 2 is divisible by i = 2
#The second beautiful arrangement is [2,1]:
#    - perm[1] = 2 is divisible by i = 1
#    - i = 2 is divisible by perm[2] = 1
#Example 2:
#Input: n = 1
#Output: 1
# 
#Constraints:
#	1 <= n <= 15
class Solution(object):
    def countArrangement(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize a list to store the results of each subproblem
        dp = [0] * (n+1)
        
        # Initialize the base case for the subproblem of size 1
        dp[1] = 1
        
        # Iterate from 2 to n
        for i in range(2, n+1):
            # Iterate from 1 to i
            for j in range(1, i+1):
                # If j is divisible by i or i is divisible by j, add the result of the subproblem of size (i-1)
                dp[i] += dp[i-1] * (j % i == 0 or i % j == 0)
        
        return dp[n]
        