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
        if not root: return []
        q = [root]
        res = []
        while q:
            n = len(q)
            max_val = float('-inf')
            for i in range(n):
                node = q.pop(0)
                max_val = max(max_val, node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            res.append(max_val)
        return res