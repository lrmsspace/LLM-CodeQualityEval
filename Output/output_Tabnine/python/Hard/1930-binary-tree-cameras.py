#https://leetcode.com/problems/binary-tree-cameras/
#You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
#Return the minimum number of cameras needed to monitor all nodes of the tree.
# 
#Example 1:
#Input: root = [0,0,null,0,0]
#Output: 1
#Explanation: One camera is enough to monitor all nodes if placed as shown.
#Example 2:
#Input: root = [0,0,null,0,null,0,null,null,0]
#Output: 2
#Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 1000].
#	Node.val == 0
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minCameraCover(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(node):
            if node is None:
                return 2  # a camera is needed at every leaf node
            
            left_cover, right_cover = dfs(node.left), dfs(node.right)
            
            if left_cover == 0 or right_cover == 0:
                return 1  # a camera is needed here
            
            if left_cover == 2 or right_cover == 2:
                return 0  # no camera is needed here
            
            return 2  # a camera is needed here
        
        return dfs(root) - 1  # subtract 1 because we don't need a camera at the root node
        