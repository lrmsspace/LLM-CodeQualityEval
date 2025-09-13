#https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
# 
#Example 1:
#Input: root = [5,3,6,2,4,null,7], k = 9
#Output: true
#Example 2:
#Input: root = [5,3,6,2,4,null,7], k = 28
#Output: false
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 104].
#	-104 <= Node.val <= 104
#	root is guaranteed to be a valid binary search tree.
#	-105 <= k <= 105
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: bool
        """
        def inorder(node):
            if node:
                inorder(node.left)
                self.nums.append(node.val)
                inorder(node.right)
        self.nums = []
        inorder(root)
        for i in range(len(self.nums)):
            for j in range(i+1, len(self.nums)):
                if self.nums[i] + self.nums[j] == k:
                    return True
        return False