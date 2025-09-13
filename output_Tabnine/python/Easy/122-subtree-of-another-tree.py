#https://leetcode.com/problems/subtree-of-another-tree/
#Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
#A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
# 
#Example 1:
#Input: root = [3,4,5,1,2], subRoot = [4,1,2]
#Output: true
#Example 2:
#Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
#Output: false
# 
#Constraints:
#	The number of nodes in the root tree is in the range [1, 2000].
#	The number of nodes in the subRoot tree is in the range [1, 1000].
#	-104 <= root.val <= 104
#	-104 <= subRoot.val <= 104
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubtree(self, root, subRoot):
        """
        :type root: Optional[TreeNode]
        :type subRoot: Optional[TreeNode]
        :rtype: bool
        """
        def isSameTree(node1, node2):
            if node1 is None and node2 is None:
                return True
            if node1 is None or node2 is None:
                return False
            if node1.val!= node2.val:
                return False
            return isSameTree(node1.left, node2.left) and isSameTree(node1.right, node2.right)
        
        if root is None:
            return False
        
        return isSameTree(root, subRoot) or self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
        