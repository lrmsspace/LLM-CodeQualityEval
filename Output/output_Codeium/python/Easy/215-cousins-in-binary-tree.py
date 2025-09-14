#https://leetcode.com/problems/cousins-in-binary-tree/
#Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
#Two nodes of a binary tree are cousins if they have the same depth with different parents.
#Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
# 
#Example 1:
#Input: root = [1,2,3,4], x = 4, y = 3
#Output: false
#Example 2:
#Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
#Output: true
#Example 3:
#Input: root = [1,2,3,null,4], x = 2, y = 3
#Output: false
# 
#Constraints:
#	The number of nodes in the tree is in the range [2, 100].
#	1 <= Node.val <= 100
#	Each node has a unique value.
#	x != y
#	x and y are exist in the tree.
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: Optional[TreeNode]
        :type x: int
        :type y: int
        :rtype: bool
        """
        parent_x, depth_x = self.dfs(root, x, None, 0)
        parent_y, depth_y = self.dfs(root, y, None, 0)
        return parent_x != parent_y and depth_x == depth_y
    
    def dfs(self, node, target, parent, depth):
        if node is None:
            return None, -1
        if node.val == target:
            return parent, depth
        left_parent, left_depth = self.dfs(node.left, target, node.val, depth + 1)
        right_parent, right_depth = self.dfs(node.right, target, node.val, depth + 1)
        if left_parent is not None:
            return left_parent, left_depth
        return right_parent, right_depth
