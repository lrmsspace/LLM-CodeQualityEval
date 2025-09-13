#https://leetcode.com/problems/find-largest-value-in-each-tree-row/
#Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
# 
#Example 1:
#Input: root = [1,3,2,5,3,null,9]
#Output: [1,3,9]
#Example 2:
#Input: root = [1,2,3]
#Output: [1,3]
# 
#Constraints:
#	The number of nodes in the tree will be in the range [0, 104].
#	-231 <= Node.val <= 231 - 1
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def largestValues(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        if not root:
            return []
        
        queue = [(root, 0)]
        max_values = []
        
        while queue:
            node, depth = queue.pop(0)
            
            if depth == len(max_values):
                max_values.append(node.val)
            else:
                max_values[depth] = max(max_values[depth], node.val)
            
            if node.left:
                queue.append((node.left, depth + 1))
            if node.right:
                queue.append((node.right, depth + 1))
        
        return max_values
        