#https://leetcode.com/problems/merge-bsts-to-create-single-bst/
#You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:
#	Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
#	Replace the leaf node in trees[i] with trees[j].
#	Remove trees[j] from trees.
#Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, or null if it is impossible to create a valid BST.
#A BST (binary search tree) is a binary tree where each node satisfies the following property:
#	Every node in the node's left subtree has a value strictly less than the node's value.
#	Every node in the node's right subtree has a value strictly greater than the node's value.
#A leaf is a node that has no children.
# 
#Example 1:
#Input: trees = [[2,1],[3,2,5],[5,4]]
#Output: [3,2,5,1,null,4]
#Explanation:
#In the first operation, pick i=1 and j=0, and merge trees[0] into trees[1].
#Delete trees[0], so trees = [[3,2,5,1],[5,4]].
#In the second operation, pick i=0 and j=1, and merge trees[1] into trees[0].
#Delete trees[1], so trees = [[3,2,5,1,null,4]].
#The resulting tree, shown above, is a valid BST, so return its root.
#Example 2:
#Input: trees = [[5,3,8],[3,2,6]]
#Output: []
#Explanation:
#Pick i=0 and j=1 and merge trees[1] into trees[0].
#Delete trees[1], so trees = [[5,3,8,2,6]].
#The resulting tree is shown above. This is the only valid operation that can be performed, but the resulting tree is not a valid BST, so return null.
#Example 3:
#Input: trees = [[5,4],[3]]
#Output: []
#Explanation: It is impossible to perform any operations.
# 
#Constraints:
#	n == trees.length
#	1 <= n <= 5 * 104
#	The number of nodes in each tree is in the range [1, 3].
#	Each node in the input may have children but no grandchildren.
#	No two roots of trees have the same value.
#	All the trees in the input are valid BSTs.
#	1 <= TreeNode.val <= 5 * 104.
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def canMerge(self, trees):
        """
        :type trees: List[TreeNode]
        :rtype: TreeNode
        """
        def dfs(node, min_val, max_val):
            if not node:
                return True
            if node.val <= min_val or node.val >= max_val:
                return False
            if node.val == float('inf'):
                return True
            node.val = float('inf')
            return dfs(node.left, min_val, node.val) and dfs(node.right, node.val, max_val)
        
        def merge(node1, node2):
            if not node1:
                return node2
            if not node2:
                return node1
            if node1.val < node2.val:
                node1.right = merge(node1.right, node2)
                return node1
            else:
                node2.right = merge(node1, node2.right)
                return node2
        
        roots = {}
        for tree in trees:
            if tree.val in roots:
                return None
            roots[tree.val] = tree
        
        for tree in trees:
            if tree.left and tree.left.val in roots:
                tree.left = roots[tree.left.val]
                del roots[tree.left.val]
            if tree.right and tree.right.val in roots:
                tree.right = roots[tree.right.val]
                del roots[tree.right.val]
        
        if len(roots) != 1:
            return None
        
        root = roots.popitem()[1]
        return root if dfs(root, float('-inf'), float('inf')) else None

        