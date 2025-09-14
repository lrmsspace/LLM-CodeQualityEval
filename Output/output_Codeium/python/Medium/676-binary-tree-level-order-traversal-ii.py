#https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
#Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
# 
#Example 1:
#Input: root = [3,9,20,null,null,15,7]
#Output: [[15,7],[9,20],[3]]
#Example 2:
#Input: root = [1]
#Output: [[1]]
#Example 3:
#Input: root = []
#Output: []
# 
#Constraints:
#	The number of nodes in the tree is in the range [0, 2000].
#	-1000 <= Node.val <= 1000
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        result, queue = [], [root]
        while queue:
            level, level_values = [], []
            for _ in range(len(queue)):
                node = queue.pop(0)
                level_values.append(node.val)
                if node.left:
                    level.append(node.left)
                if node.right:
                    level.append(node.right)
            result.append(level_values)
            queue = level
        
        return result[::-1]
