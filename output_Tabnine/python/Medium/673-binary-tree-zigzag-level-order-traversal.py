#https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
#Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
# 
#Example 1:
#Input: root = [3,9,20,null,null,15,7]
#Output: [[3],[20,9],[15,7]]
#Example 2:
#Input: root = [1]
#Output: [[1]]
#Example 3:
#Input: root = []
#Output: []
# 
#Constraints:
#	The number of nodes in the tree is in the range [0, 2000].
#	-100 <= Node.val <= 100
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        result, stack = [], [(root, 0)]
        
        while stack:
            current_level, level_size = [], len(stack)
            
            for _ in range(level_size):
                node, level = stack.pop(0)
                current_level.append(node.val)
                
                if level % 2 == 0:
                    if node.left:
                        stack.append((node.left, level + 1))
                    if node.right:
                        stack.append((node.right, level + 1))
                else:
                    if node.right:
                        stack.append((node.right, level + 1))
                    if node.left:
                        stack.append((node.left, level + 1))
            
            result.append(current_level)
        
        return result
        