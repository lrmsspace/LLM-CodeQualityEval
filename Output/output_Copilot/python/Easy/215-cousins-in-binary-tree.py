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
        if not root:
            return False

        queue = [(root, 0, None)]        
        x_depth = y_depth = -1
        x_parent = y_parent = None
        while queue:
            node, depth, parent = queue.pop(0)
            if node.val == x:
                x_depth = depth
                x_parent = parent
            elif node.val == y:
                y_depth = depth
                y_parent = parent

            if x_depth != -1 and y_depth != -1:
                break

            if node.left:
                queue.append((node.left, depth + 1, node))
            if node.right:
                queue.append((node.right, depth + 1, node))
        return x_depth == y_depth and x_parent != y_parent