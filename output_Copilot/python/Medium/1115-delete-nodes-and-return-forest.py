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
        def dfs(node, to_delete_set):
            if not node:
                return None
            if node.val in to_delete_set:
                # If the current node is to be deleted, return None
                return None
            # Recursively delete nodes in the left and right subtrees
            node.left = dfs(node.left, to_delete_set)
            node.right = dfs(node.right, to_delete_set)
            return node

        # Convert to_delete list to a set for O(1) lookups
        to_delete_set = set(to_delete)
        # Start DFS traversal from the root
        remaining_forest = []
        if root.val not in to_delete_set:
            remaining_forest.append(root)
        root = dfs(root, to_delete_set)
        # Collect the roots of the remaining trees in the forest
        return remaining_forest + [node for node in self.delNodes(root, to_delete) if node]        