#https://leetcode.com/problems/delete-nodes-and-return-forest/
#Given the root of a binary tree, each node in the tree has a distinct value.
#After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
#Return the roots of the trees in the remaining forest. You may return the result in any order.
# 
#Example 1:
#Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
#Output: [[1,2,null,4],[6],[7]]
#Example 2:
#Input: root = [1,2,4,null,3], to_delete = [3]
#Output: [[1,2,4]]
# 
#Constraints:
#	The number of nodes in the given tree is at most 1000.
#	Each node has a distinct value between 1 and 1000.
#	to_delete.length <= 1000
#	to_delete contains distinct values between 1 and 1000.
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        def dfs(node, parent):
            if not node:
                return None
            
            if node.val in to_delete:
                if parent:
                    if parent.left == node:
                        parent.left = dfs(node.right, parent)
                    else:
                        parent.right = dfs(node.right, parent)
                return None
            
            node.left = dfs(node.left, node)
            node.right = dfs(node.right, node)
            
            return node
        
        roots = []
        dfs(root, None)
        
        for node in [root] + roots:
            if node and node.val not in to_delete:
                roots.append(node)
        
        return roots
        