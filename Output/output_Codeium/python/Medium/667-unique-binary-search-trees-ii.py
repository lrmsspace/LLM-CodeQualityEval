#https://leetcode.com/problems/unique-binary-search-trees-ii/
#Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
# 
#Example 1:
#Input: n = 3
#Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
#Example 2:
#Input: n = 1
#Output: [[1]]
# 
#Constraints:
#	1 <= n <= 8
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[Optional[TreeNode]]
        """
        if n == 0:
            return []
        res = []
        for i in range(1, n+1):
            lefts = self.generateTrees(i-1)
            rights = self.generateTrees(n-i)
            for l in lefts:
                for r in rights:
                    r = TreeNode(i)
                    r.left = l
                    r.right = r
                    res.append(r)
        return res
