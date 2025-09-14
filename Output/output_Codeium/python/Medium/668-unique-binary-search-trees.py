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
        #base case
        if n == 0:
            return 1
        elif n == 1:
            return 1
        else:
            #generate all possible unique BSTs
            total = 0
            for i in range(1, n+1):
                left = self.numTrees(i-1)
                right = self.numTrees(n-i)
                total += left*right
            return total
